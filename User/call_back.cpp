#include "call_back.hpp"
#include "chassis.hpp"
#include "clamp.hpp"
#include "error_handle.hpp"
#include "power_limit.hpp"
#include "variables.hpp"

constexpr auto vofa_cnt = 2;

float testvalue;

/*void CanCallBack(CAN_HandleTypeDef* hcan)*/
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* hcan) {
    if (hcan->Instance == kMotorCan->Instance) {

        CAN_RxHeaderTypeDef rx_header{0};
        uint8_t buf[8]{0};

        HAL_CAN_GetRxMessage(kMotorCan, CAN_RX_FIFO0, &rx_header, buf);  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½

        for (uint8_t i = 0; i < kMotorCount; i++) {
            if (rx_header.StdId == dji_motor_list[i]->recv_id_) {
                dji_motor_list[i]->DataUpdate(buf);  //ï¿½ï¿½ï¿½Âµï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
                dji_motor_list[i]->is_reply_ = true;  //Ó¦ï¿½ï¿½
                break;
            }
        }
    } else if (hcan->Instance == kCapacityCan->Instance) {

        CAN_RxHeaderTypeDef rx_header{0};
        uint8_t buf[8]{0};

        HAL_CAN_GetRxMessage(kCapacityCan, CAN_RX_FIFO0, &rx_header,
                             buf);  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½

        //  ============================= °²ºÏµçÈÝ =================================
        if (rx_header.StdId == 0x611) {
            capacity.target_power = ((float)(buf[0] << 8 | buf[1]) / 100.0f);
        } else if (rx_header.StdId == 0x612) {
            capacity.voltage = ((float)(buf[2] << 8 | buf[3]) / 100.0f);
        }
        //  =======================================================================

        //  ============================= ×ÔÑÐµçÈÝ =================================
        // if (rx_header.StdId == 0x715) {
        //     capacity.voltage = ((float)(buf[0] << 8 | buf[1]) / 100.0f);
        //     capacity.target_power = ((float)(buf[2] << 8 | buf[3]) / 10000.0f);
        // }
        //  =======================================================================

        capacity.is_reply_ = true;  //Ó¦ï¿½ï¿½
    }
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef* huart, uint16_t Size) {
    if (huart->Instance == kCommUart->Instance) {
        if (Size == kCommRecvSize) {
            comm.RecvUpdate(comm_rx_buf);  //Í¨ï¿½ï¿½ï¿½ï¿½ï¿½Ý¸ï¿½ï¿½ï¿½
            comm.is_reply_ = true;         //Ó¦ï¿½ï¿½
        }
        //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
        HAL_UARTEx_ReceiveToIdle_DMA(kCommUart, comm_rx_buf, kCommRecvSize);
    } else if (huart->Instance == kRefereeUart->Instance) {
        referee.recv_size = Size;
        referee.FrameProcessing(referee_rx_buf);
        referee.is_reply = true;
        //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
        HAL_UARTEx_ReceiveToIdle_DMA(kRefereeUart, referee_rx_buf, kRefereeRecvSize);
    }
}

void MainCallBack() {
    /*  =========================== ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿? ===========================  */

    //201×ªï¿½ï¿½PID
    auto measure_rpm_201 = td_201.Compute(
        motor_201.actual_rpm_);  //ï¿½ï¿½È¡Î¢ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë²ï¿½ï¿½ï¿½×ªï¿½ï¿½
    auto dji_motor_201_input = pid_vel_201.Compute(target_rpm_201, measure_rpm_201);
    motor_201.input_ = dji_motor_201_input;  //ï¿½ï¿½ï¿½Ãµï¿½ï¿½ï¿½ï¿½ï¿½

    //202×ªï¿½ï¿½PID
    auto measure_rpm_202 = td_202.Compute(
        motor_202.actual_rpm_);  //ï¿½ï¿½È¡Î¢ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë²ï¿½ï¿½ï¿½×ªï¿½ï¿½
    auto dji_motor_202_input = pid_vel_202.Compute(target_rpm_202, measure_rpm_202);
    motor_202.input_ = dji_motor_202_input;  //ï¿½ï¿½ï¿½Ãµï¿½ï¿½ï¿½ï¿½ï¿½

    //203×ªï¿½ï¿½PID
    auto measure_rpm_203 = td_203.Compute(
        motor_203.actual_rpm_);  //ï¿½ï¿½È¡Î¢ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë²ï¿½ï¿½ï¿½×ªï¿½ï¿½
    auto dji_motor_203_input = pid_vel_203.Compute(target_rpm_203, measure_rpm_203);
    motor_203.input_ = dji_motor_203_input;  //ï¿½ï¿½ï¿½Ãµï¿½ï¿½ï¿½ï¿½ï¿½

    //204×ªï¿½ï¿½PID
    auto measure_rpm_204 = td_204.Compute(
        motor_204.actual_rpm_);  //ï¿½ï¿½È¡Î¢ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë²ï¿½ï¿½ï¿½×ªï¿½ï¿½
    auto dji_motor_204_input = pid_vel_204.Compute(target_rpm_204, measure_rpm_204);
    motor_204.input_ = dji_motor_204_input;  //ï¿½ï¿½ï¿½Ãµï¿½ï¿½ï¿½ï¿½ï¿½

    //  ======================= ²âÊÔ×ÔÑÐµçÈÝ×é add in 2024/7/29 =======================
    // PowerCare();  //¹¦ÂÊÏÞÖµ
	// 	if(referee.power_heat_data.buffer_energy < testvalue){
    //         testvalue = referee.power_heat_data.buffer_energy;
    //     }
    //  ==============================================================================

    DjiMotorSend();  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý·ï¿½ï¿½ï¿?

    // uint8_t send_str2[(vofa_cnt + 1) * 4] = {0};
    // *((float*)&send_str2[0 * 4]) = (float)motor_201.actual_rpm_;
    // *((float*)&send_str2[1 * 4]) = (float)0;
    // *((uint32_t*)&send_str2[sizeof(float) * (vofa_cnt)]) = 0x7f800000;
    // //ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    // HAL_UART_Transmit_DMA(&huart6, send_str2, sizeof(float) * (vofa_cnt + 1));
}

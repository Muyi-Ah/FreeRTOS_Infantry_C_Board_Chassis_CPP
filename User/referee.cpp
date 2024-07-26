#include "referee.hpp"
#include <cstring>
#include "crc.hpp"

void Referee::FrameProcessing(uint8_t* buf) {
    for (uint16_t i = 0; i < recv_size; i++) {

        //在一整个空闲中断的数据中寻找帧头
        if (buf[i] == 0xA5) {

            //找到帧头后进行CRC8校验
            if (Verify_CRC8_Check_Sum(buf + i, kFrameHeaderLength)) {
                memcpy(&header, buf + i, kFrameHeaderLength);

                //进行CRC16校验
                if (Verify_CRC16_Check_Sum(buf + i, kFrameHeaderLength + kCmdIdLength +
                                                        header.data_length + kFrameTailLength)) {
                    memcpy(&cmd_id, buf + i + kFrameHeaderLength, kCmdIdLength);

                    switch (cmd_id) {
                        case 0x201:
                            memcpy(&robot_status, buf + i + kFrameHeaderLength + kCmdIdLength,
                                   sizeof(robot_status_t));
                            break;

                        case 0x202:
                            memcpy(&power_heat_data, buf + i + kFrameHeaderLength + kCmdIdLength,
                                   sizeof(power_heat_data_t));
                            break;

                        case 0x206:
                            memcpy(&hurt_data, buf + i + kFrameHeaderLength + kCmdIdLength,
                                   sizeof(hurt_data_t));
                            break;

                        default:
                            break;
                    }
                }
            }
        }
    }
}
/**
 * @file capacity.cpp
 * @author XMX
 * @brief ���ϳ��������෽��
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "capacity.hpp"
#include "can.hpp"

/// @brief ʹ�����
void Capacity::EnableOutput() {
    CAN_TxHeaderTypeDef tx_header{0};
    uint8_t tx_buf[8]{0};

    tx_header.StdId = 0x600;
    tx_header.ExtId = 0;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    tx_header.TransmitGlobalTime = DISABLE;

    tx_buf[1] = 2;

    HAL_CAN_AddTxMessage(kCapacityCan, &tx_header, tx_buf, (uint32_t*)CAN_TX_MAILBOX0);
}

/// @brief ��������繦��
/// @param more_power 
void Capacity::SetMaxChargePower(uint16_t more_power) {
    CAN_TxHeaderTypeDef tx_header{0};
    uint8_t tx_buf[8]{0};

    tx_header.StdId = 0x601;
    tx_header.ExtId = 0;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    tx_header.TransmitGlobalTime = DISABLE;

    tx_buf[0] = (charge_power+more_power) >> 8;
    tx_buf[1] = (charge_power+more_power);

    HAL_CAN_AddTxMessage(kCapacityCan, &tx_header, tx_buf, (uint32_t*)CAN_TX_MAILBOX0);
}

/// @brief ��ѯ�������ѹ
void Capacity::AskVoltage() {
    CAN_TxHeaderTypeDef tx_header{0};
    uint8_t tx_buf[8]{0};

    tx_header.StdId = 0x612;
    tx_header.ExtId = 0;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_REMOTE;
    tx_header.DLC = 8;
    tx_header.TransmitGlobalTime = DISABLE;


    HAL_CAN_AddTxMessage(kCapacityCan, &tx_header, tx_buf, (uint32_t*)CAN_TX_MAILBOX0);
}

/// @brief ��ѯ���빦��
void Capacity::AskInputPower() {
    CAN_TxHeaderTypeDef tx_header{0};
    uint8_t tx_buf[8]{0};

    tx_header.StdId = 0x611;
    tx_header.ExtId = 0;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_REMOTE;
    tx_header.DLC = 8;
    tx_header.TransmitGlobalTime = DISABLE;

    HAL_CAN_AddTxMessage(kCapacityCan, &tx_header, tx_buf, (uint32_t*)CAN_TX_MAILBOX0);
}

/// @brief ���е�����
void Capacity::Ask_RCIA() {
    CAN_TxHeaderTypeDef tx_header{0};
    uint8_t tx_buf[8]{0};

    tx_header.StdId = 0x715;
    tx_header.ExtId = 0;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    tx_header.TransmitGlobalTime = DISABLE;

    HAL_CAN_AddTxMessage(kCapacityCan, &tx_header, tx_buf, (uint32_t*)CAN_TX_MAILBOX0);
}

/// @brief ���е�����
void Capacity::SetMaxChargePower_RCIA() {
    CAN_TxHeaderTypeDef tx_header{0};
    uint8_t tx_buf[8]{0};

    tx_header.StdId = 0x615;
    tx_header.ExtId = 0;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    tx_header.TransmitGlobalTime = DISABLE;

    tx_buf[0] = charge_power >> 8;
    tx_buf[1] = charge_power;

    HAL_CAN_AddTxMessage(kCapacityCan, &tx_header, tx_buf, (uint32_t*)CAN_TX_MAILBOX0);
}

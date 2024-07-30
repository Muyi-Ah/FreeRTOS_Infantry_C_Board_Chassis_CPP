#include "capacity.hpp"
#include "can.hpp"

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

void Capacity::SetMaxChargePower() {
    CAN_TxHeaderTypeDef tx_header{0};
    uint8_t tx_buf[8]{0};

    tx_header.StdId = 0x601;
    tx_header.ExtId = 0;
    tx_header.IDE = CAN_ID_STD;
    tx_header.RTR = CAN_RTR_DATA;
    tx_header.DLC = 8;
    tx_header.TransmitGlobalTime = DISABLE;

    tx_buf[0] = charge_power >> 8;
    tx_buf[1] = charge_power;

    HAL_CAN_AddTxMessage(kCapacityCan, &tx_header, tx_buf, (uint32_t*)CAN_TX_MAILBOX0);
}

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

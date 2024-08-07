/**
 * @file can.cpp
 * @author XMX
 * @brief CAN外设初始化
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "can.hpp"
#include "call_back.hpp"
#include "error_handle.hpp"

/// @brief CAN初始化
void CanInit() {

    CAN_FilterTypeDef CAN_FilterInitStructure1{0};

    CAN_FilterInitStructure1.FilterIdHigh = 0x0000;
    CAN_FilterInitStructure1.FilterIdLow = 0x0000;
    CAN_FilterInitStructure1.FilterMaskIdHigh = 0x0000;
    CAN_FilterInitStructure1.FilterMaskIdLow = 0x0000;
    CAN_FilterInitStructure1.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    CAN_FilterInitStructure1.FilterBank = 0;
    CAN_FilterInitStructure1.FilterMode = CAN_FILTERMODE_IDMASK;
    CAN_FilterInitStructure1.FilterScale = CAN_FILTERSCALE_32BIT;
    CAN_FilterInitStructure1.FilterActivation = CAN_FILTER_ENABLE;
    CAN_FilterInitStructure1.SlaveStartFilterBank = 14;

    HAL_CAN_ConfigFilter(kMotorCan, &CAN_FilterInitStructure1);

    HAL_CAN_ActivateNotification(kMotorCan, CAN_IT_RX_FIFO0_MSG_PENDING);

    HAL_CAN_Start(kMotorCan);

    HAL_Delay(10);

    CAN_FilterTypeDef CAN_FilterInitStructure2{0};

    CAN_FilterInitStructure2.FilterIdHigh = 0x0000;
    CAN_FilterInitStructure2.FilterIdLow = 0x0000;
    CAN_FilterInitStructure2.FilterMaskIdHigh = 0x0000;
    CAN_FilterInitStructure2.FilterMaskIdLow = 0x0000;
    CAN_FilterInitStructure2.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    CAN_FilterInitStructure2.FilterBank = 15;
    CAN_FilterInitStructure2.FilterMode = CAN_FILTERMODE_IDMASK;
    CAN_FilterInitStructure2.FilterScale = CAN_FILTERSCALE_32BIT;
    CAN_FilterInitStructure2.FilterActivation = CAN_FILTER_ENABLE;
    CAN_FilterInitStructure2.SlaveStartFilterBank = 14;

    HAL_CAN_ConfigFilter(kCapacityCan, &CAN_FilterInitStructure2);

    HAL_CAN_ActivateNotification(kCapacityCan, CAN_IT_RX_FIFO0_MSG_PENDING);

    HAL_CAN_Start(kCapacityCan);
}
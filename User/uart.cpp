/**
 * @file uart.cpp
 * @author XMX
 * @brief 串口相关
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "uart.hpp"
#include "call_back.hpp"
#include "error_handle.hpp"

uint8_t comm_rx_buf[kCommRecvSize];      //板间通信数据接收数组
uint8_t referee_rx_buf[kRefereeRecvSize];  //裁判系统数据接收数组

/// @brief 串口初始化
void UartInit() {
	HAL_UARTEx_ReceiveToIdle_DMA(kCommUart, comm_rx_buf, kCommRecvSize);
    HAL_UARTEx_ReceiveToIdle_DMA(kRefereeUart, referee_rx_buf, kRefereeRecvSize);
}

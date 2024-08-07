/**
 * @file uart.cpp
 * @author XMX
 * @brief �������
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "uart.hpp"
#include "call_back.hpp"
#include "error_handle.hpp"

uint8_t comm_rx_buf[kCommRecvSize];      //���ͨ�����ݽ�������
uint8_t referee_rx_buf[kRefereeRecvSize];  //����ϵͳ���ݽ�������

/// @brief ���ڳ�ʼ��
void UartInit() {
	HAL_UARTEx_ReceiveToIdle_DMA(kCommUart, comm_rx_buf, kCommRecvSize);
    HAL_UARTEx_ReceiveToIdle_DMA(kRefereeUart, referee_rx_buf, kRefereeRecvSize);
}

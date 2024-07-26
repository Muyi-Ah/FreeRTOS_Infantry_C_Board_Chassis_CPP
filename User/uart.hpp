#pragma once
#include "usart.h"

constexpr UART_HandleTypeDef* kCommUart = &huart1;  //���ͨ�Ŵ���
constexpr UART_HandleTypeDef* kRefereeUart = &huart6;  //����ϵͳ���ݴ���

constexpr uint16_t kCommRecvSize = 34;  //���ͨ�������ֽ���
constexpr uint16_t kCommSendSize = 1;
constexpr uint16_t kRefereeRecvSize = 512;  //����ϵͳ�����ֽ���

extern uint8_t comm_rx_buf[kCommRecvSize];      //���ͨ�����ݽ�������
extern uint8_t referee_rx_buf[kRefereeRecvSize];  //����ϵͳ���ݽ�������

void UartInit();

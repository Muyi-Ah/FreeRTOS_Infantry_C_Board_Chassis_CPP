#pragma once
#include "usart.h"

constexpr UART_HandleTypeDef* kCommUart = &huart1;  //板间通信串口
constexpr UART_HandleTypeDef* kRefereeUart = &huart6;  //裁判系统数据串口

constexpr uint16_t kCommRecvSize = 34;  //板间通信数据字节数
constexpr uint16_t kCommSendSize = 1;
constexpr uint16_t kRefereeRecvSize = 512;  //裁判系统数据字节数

extern uint8_t comm_rx_buf[kCommRecvSize];      //板间通信数据接收数组
extern uint8_t referee_rx_buf[kRefereeRecvSize];  //裁判系统数据接收数组

void UartInit();

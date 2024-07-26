#include "uart.hpp"
#include "call_back.hpp"
#include "error_handle.hpp"

uint8_t comm_rx_buf[kCommRecvSize];      //板间通信数据接收数组
uint8_t referee_rx_buf[kRefereeRecvSize];  //裁判系统数据接收数组

/**
* 串口初始化.
*/
void UartInit() {
	//注册中断回调函数 @warning 中断注册须在启动接收前
	//HAL_UART_RegisterRxEventCallback(kRemoteUart, UartCallBack);
	//HAL_UART_RegisterRxEventCallback(kCommUart, UartCallBack);
	//HAL_UART_RegisterRxEventCallback(kVisionUart, UartCallBack);

	HAL_UARTEx_ReceiveToIdle_DMA(kCommUart, comm_rx_buf, kCommRecvSize);
    HAL_UARTEx_ReceiveToIdle_DMA(kRefereeUart, referee_rx_buf, kRefereeRecvSize);
}

#include "uart.hpp"
#include "call_back.hpp"
#include "error_handle.hpp"

uint8_t comm_rx_buf[kCommRecvSize];      //���ͨ�����ݽ�������
uint8_t referee_rx_buf[kRefereeRecvSize];  //����ϵͳ���ݽ�������

/**
* ���ڳ�ʼ��.
*/
void UartInit() {
	//ע���жϻص����� @warning �ж�ע��������������ǰ
	//HAL_UART_RegisterRxEventCallback(kRemoteUart, UartCallBack);
	//HAL_UART_RegisterRxEventCallback(kCommUart, UartCallBack);
	//HAL_UART_RegisterRxEventCallback(kVisionUart, UartCallBack);

	HAL_UARTEx_ReceiveToIdle_DMA(kCommUart, comm_rx_buf, kCommRecvSize);
    HAL_UARTEx_ReceiveToIdle_DMA(kRefereeUart, referee_rx_buf, kRefereeRecvSize);
}

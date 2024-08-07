/**
 * @file init.cpp
 * @author XMX
 * @brief ��ʼ������
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "init.hpp"
#include "can.hpp"
#include "uart.hpp"
#include "tim.h"

/// @brief ��ʼ��
void init() {
    UartInit();
    CanInit();
    HAL_TIM_Base_Start_IT(&htim7);
}

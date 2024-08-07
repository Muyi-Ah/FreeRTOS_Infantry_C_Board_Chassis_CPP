/**
 * @file communication_task.cpp
 * @author XMX
 * @brief ���ͨ�ŷ�������
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "communication_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

/// @brief ���ͨ�ŷ�������
/// @param argument 
void CommunicationTask(void* argument) {
    for (;;) {
        comm.Send();
        osDelay(2);
    }
}
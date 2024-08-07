/**
 * @file communication_task.cpp
 * @author XMX
 * @brief 板间通信发送任务
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "communication_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

/// @brief 板间通信发送任务
/// @param argument 
void CommunicationTask(void* argument) {
    for (;;) {
        comm.Send();
        osDelay(2);
    }
}
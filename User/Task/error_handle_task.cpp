/**
 * @file error_handle_task.cpp
 * @author XMX
 * @brief 错误检测任务
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "error_handle_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

/// @brief 错误检测任务
/// @param argument 
void ErrorHandleTask(void* argument) {
    for (;;) {
        error_handle.Check();
        error_handle.Handle();
        osDelay(100);
    }
}
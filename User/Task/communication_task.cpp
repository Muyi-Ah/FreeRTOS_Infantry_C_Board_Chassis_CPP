#include "communication_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

/// @brief 板间通信任务
/// @param argument 
void CommunicationTask(void* argument) {
    for (;;) {
        comm.Send();
        osDelay(2);
    }
}
#include "communication_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

/// @brief ���ͨ������
/// @param argument 
void CommunicationTask(void* argument) {
    for (;;) {
        comm.Send();
        osDelay(2);
    }
}
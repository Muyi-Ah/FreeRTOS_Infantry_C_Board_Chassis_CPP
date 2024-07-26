#include "communication_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

void CommunicationTask(void* argument) {
    for (;;) {
        comm.Send();
        osDelay(2);
    }
}
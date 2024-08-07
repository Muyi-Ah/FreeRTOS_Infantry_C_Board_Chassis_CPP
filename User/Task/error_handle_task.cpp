#include "error_handle_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

/// @brief ´íÎó¼ì²âÈÎÎñ
/// @param argument 
void ErrorHandleTask(void* argument) {
    for (;;) {
        error_handle.Check();
        error_handle.Handle();
        osDelay(100);
    }
}
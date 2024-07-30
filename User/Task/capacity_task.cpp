#include "capacity_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

void CapacityTask(void* argument) {
    for (;;) {
        //  ============================= 安合电容 =================================
        capacity.EnableOutput();
        osDelay(250);
        capacity.SetMaxChargePower();
        osDelay(250);
        capacity.AskVoltage();
        osDelay(250);
        capacity.AskInputPower();
        osDelay(250);
        //  ========================================================================

        // capacity.Ask_RCIA();  //自研电容数据查询
        // osDelay(250);
        // capacity.SetMaxChargePower_RCIA();  //自研电容组功率设置
        // osDelay(250);
    }
}
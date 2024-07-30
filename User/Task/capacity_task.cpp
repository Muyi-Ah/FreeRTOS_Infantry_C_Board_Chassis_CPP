#include "capacity_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

void CapacityTask(void* argument) {
    for (;;) {
        //  ============================= ���ϵ��� =================================
        capacity.EnableOutput();
        osDelay(250);
        capacity.SetMaxChargePower();
        osDelay(250);
        capacity.AskVoltage();
        osDelay(250);
        capacity.AskInputPower();
        osDelay(250);
        //  ========================================================================

        // capacity.Ask_RCIA();  //���е������ݲ�ѯ
        // osDelay(250);
        // capacity.SetMaxChargePower_RCIA();  //���е����鹦������
        // osDelay(250);
    }
}
/**
 * @file capacity_task.cpp
 * @author XMX
 * @brief ���ݲ�ѯ����������
 * @version 1.0
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "capacity_task.hpp"
#include "FreeRTOS.h"
#include "cmsis_os2.h"
#include "variables.hpp"

uint16_t more_power;

/**
 * @brief ���ݲ�ѯ����������
 * 
 * @param argument 
 */
void CapacityAskTask(void* argument) {
    for (;;) {
        //  ============================= ���ϵ��� =================================
        capacity.EnableOutput();
        osDelay(35);
        capacity.AskVoltage();
        osDelay(35);
        capacity.AskInputPower();
        osDelay(35);
        capacity.SetMaxChargePower(more_power);
        osDelay(35);
        //  ========================================================================

        // capacity.Ask_RCIA();  //���е������ݲ�ѯ
        // osDelay(250);
        // capacity.SetMaxChargePower_RCIA();  //���е����鹦������
        // osDelay(250);
    }
}

/**
 * @brief ���ݳ�繦�ʷ�������δʹ�� ����2024/8/7��
 * 
 * @param argument 
 */
void CapacityChargeTask(void* argument) {
    for (;;) {
        // //buffer_energy���Ϊ60
        // auto normalize_buffer = (referee.power_heat_data.buffer_energy - 20) / 40.0f;
        // //2.0fָ����2W���ʣ�����Э����Ŵ�1000��
        // uint16_t more_power = (normalize_buffer * 2.0f) * 1000.0f;
        // capacity.SetMaxChargePower(more_power);

        //����ʱ��
        auto tick = osKernelGetTickCount();
        tick += pdMS_TO_TICKS(20);
        osDelayUntil(tick);
    }
}
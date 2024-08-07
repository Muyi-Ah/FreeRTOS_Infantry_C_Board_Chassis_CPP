/**
 * @file referee_detect_task.cpp
 * @author XMX
 * @brief 与裁判系统数据相关的检测任务
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "referee_detect_task.hpp"
#include "chassis.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"

extern uint16_t more_power;

void capacity_power_detection();

/// @brief 功率保护任务
/// @param argument 
void RefereeDetectTask(void* argument) {
    for (;;) {
        capacity_power_detection();  //底盘功率检测
        osDelay(100);
    }
}

/// @brief 充电功率选择
void capacity_power_detection() {
    if (referee.power_heat_data.buffer_energy < 20) {
        more_power = -200;
    } else {
        more_power = 0;
    }

    switch (referee.robot_status.chassis_power_limit) {

        case 45:
            capacity.charge_power = 4200;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 1900;
            }
            break;

        case 50:
            capacity.charge_power = 4700;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 2100;
            }
            break;

        case 55:
            capacity.charge_power = 5200;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 2300;
            }
            break;

        case 60:
            capacity.charge_power = 5700;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 2500;
            }
            break;

        case 65:
            capacity.charge_power = 6200;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 2600;
            }
            break;

        case 70:
            capacity.charge_power = 6700;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 2700;
            }
            break;

        case 75:
            capacity.charge_power = 7200;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 2900;
            }
            break;

        case 80:
            capacity.charge_power = 7700;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 3200;
            }
            break;

        case 85:
            capacity.charge_power = 8200;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 3350;
            }
            break;

        case 90:
            capacity.charge_power = 8700;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 3500;
            }
            break;

        case 95:
            capacity.charge_power = 9200;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 3750;
            }
            break;

        case 100:
            capacity.charge_power = 9700;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 4000;
            }
            break;

        case 120:
            capacity.charge_power = 11700;
            if (adjust_max_rpm_flag == false) {
                max_rpm = 6000;
            }
            break;

        default:
            break;
    }
}
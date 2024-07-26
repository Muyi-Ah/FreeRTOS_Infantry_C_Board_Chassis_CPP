#include "referee_detect_task.hpp"
#include "cmsis_os2.h"
#include "variables.hpp"
#include "chassis.hpp"

void capacity_power_detection();

void RefereeDetectTask(void* argument) {
    for (;;) {
        capacity_power_detection();  //µ×ÅÌ¹¦ÂÊ¼ì²â
        osDelay(100);
    }
}

void capacity_power_detection() {
    switch (referee.robot_status.chassis_power_limit) {

        case 45:
            capacity.charge_power = 4400;
            max_rpm = 1900;
            break;

        case 50:
            capacity.charge_power = 4900;
            max_rpm = 2100;
            break;

        case 55:
            capacity.charge_power = 5400;
            max_rpm = 2300;
            break;

        case 60:
            capacity.charge_power = 5900;
            max_rpm = 2500;
            break;

        case 65:
            capacity.charge_power = 6400;
            max_rpm = 2600;
            break;

        case 70:
            capacity.charge_power = 6900;
            max_rpm = 2700;
            break;

        case 75:
            capacity.charge_power = 7400;
            max_rpm = 2900;
            break;

        case 80:
            capacity.charge_power = 7900;
            max_rpm = 3200;
            break;

        case 85:
            capacity.charge_power = 8400;
            max_rpm = 3350;
            break;

        case 90:
            capacity.charge_power = 8900;
            max_rpm = 3500;
            break;

        case 95:
            capacity.charge_power = 9400;
            max_rpm = 3750;
            break;

        case 100:
            capacity.charge_power = 9900;
            max_rpm = 4000;
            break;

        default:
            break;
    }
}
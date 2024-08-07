/**
 * @file power_limit.cpp
 * @author XMX
 * @brief 串联超级电容的功率限制算法（未经完全测试）
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "power_limit.hpp"
#include "config.hpp"
#include "variables.hpp"

float maximum_power;

/// @brief 功率限制
void PowerCare() {
    //各电机电流
    auto i1 = motor_201.actual_current_;
    auto i2 = motor_202.actual_current_;
    auto i3 = motor_203.actual_current_;
    auto i4 = motor_204.actual_current_;

    if (referee.power_heat_data.buffer_energy > kWarningPowerBuffer) {
        //计算可用最大功率
        maximum_power = (referee.power_heat_data.buffer_energy - kWarningPowerBuffer) / 0.02f;
    } else {
        //功率限制
        maximum_power = referee.robot_status.chassis_power_limit;
    }

    //计算总电流
    auto chassis_motor_current = i1 + i2 + i3 + i4;

    //计算各电机输出
    if (chassis_motor_current / 819.2 * kDefaultBatteryVoltage > maximum_power) {
        motor_201.input_ = i1 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
        motor_202.input_ = i2 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
        motor_203.input_ = i3 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
        motor_204.input_ = i4 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
    }
}
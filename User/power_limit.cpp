/**
 * @file power_limit.cpp
 * @author XMX
 * @brief �����������ݵĹ��������㷨��δ����ȫ���ԣ�
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

/// @brief ��������
void PowerCare() {
    //���������
    auto i1 = motor_201.actual_current_;
    auto i2 = motor_202.actual_current_;
    auto i3 = motor_203.actual_current_;
    auto i4 = motor_204.actual_current_;

    if (referee.power_heat_data.buffer_energy > kWarningPowerBuffer) {
        //������������
        maximum_power = (referee.power_heat_data.buffer_energy - kWarningPowerBuffer) / 0.02f;
    } else {
        //��������
        maximum_power = referee.robot_status.chassis_power_limit;
    }

    //�����ܵ���
    auto chassis_motor_current = i1 + i2 + i3 + i4;

    //�����������
    if (chassis_motor_current / 819.2 * kDefaultBatteryVoltage > maximum_power) {
        motor_201.input_ = i1 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
        motor_202.input_ = i2 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
        motor_203.input_ = i3 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
        motor_204.input_ = i4 / chassis_motor_current * (maximum_power / kDefaultBatteryVoltage);
    }
}
/**
 * @file error_handle.cpp
 * @author XMX
 * @brief �������෽��
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "error_handle.hpp"
#include <cstdint>
#include "variables.hpp"

/// @brief ������
void ErrorHandle::Check() {
    //������
    for (uint8_t i = 0; i < kMotorCount; i++) {
        if (dji_motor_list[i]->is_reply_) {
            dji_motor_list[i]->is_reply_ = false;
            motor_is_offline[i] = false;
        } else {
            motor_is_offline[i] = true;
        }
    }

    //���ͨ�ż��
    if (comm.is_reply_) {
        comm.is_reply_ = false;
        communication_is_offline = false;
    } else {
        communication_is_offline = true;
    }

    //����ϵͳͨ�ż��
    if (referee.is_reply) {
        referee.is_reply = false;
        referee_is_offline = false;
    } else {
        referee_is_offline = true;
    }
}

/// @brief ������
void ErrorHandle::Handle() {
    for (uint8_t i = 0; i < kMotorCount; i++) {

        //�����������
        if (motor_is_offline[i]) {
            //@developing...
        }
    }

    //���ͨ�Ŷ�������
    if (communication_is_offline) {
        dr16.remote_.ch0_ = 1024;
        dr16.remote_.ch1_ = 1024;
        dr16.remote_.ch2_ = 1024;
        dr16.remote_.ch3_ = 1024;
        dr16.remote_.s1_ = 1;
        dr16.remote_.s2_ = 1;
        dr16.remote_.wheel_ = 1024;
    }

    //����ϵͳ��������
    if (referee_is_offline) {
        //@developing...
    }
}

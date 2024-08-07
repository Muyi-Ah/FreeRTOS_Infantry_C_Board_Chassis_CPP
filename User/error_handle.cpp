/**
 * @file error_handle.cpp
 * @author XMX
 * @brief 错误检测类方法
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "error_handle.hpp"
#include <cstdint>
#include "variables.hpp"

/// @brief 错误检测
void ErrorHandle::Check() {
    //电机检测
    for (uint8_t i = 0; i < kMotorCount; i++) {
        if (dji_motor_list[i]->is_reply_) {
            dji_motor_list[i]->is_reply_ = false;
            motor_is_offline[i] = false;
        } else {
            motor_is_offline[i] = true;
        }
    }

    //板间通信检测
    if (comm.is_reply_) {
        comm.is_reply_ = false;
        communication_is_offline = false;
    } else {
        communication_is_offline = true;
    }

    //裁判系统通信检测
    if (referee.is_reply) {
        referee.is_reply = false;
        referee_is_offline = false;
    } else {
        referee_is_offline = true;
    }
}

/// @brief 错误处理
void ErrorHandle::Handle() {
    for (uint8_t i = 0; i < kMotorCount; i++) {

        //电机断联处理
        if (motor_is_offline[i]) {
            //@developing...
        }
    }

    //板间通信断联处理
    if (communication_is_offline) {
        dr16.remote_.ch0_ = 1024;
        dr16.remote_.ch1_ = 1024;
        dr16.remote_.ch2_ = 1024;
        dr16.remote_.ch3_ = 1024;
        dr16.remote_.s1_ = 1;
        dr16.remote_.s2_ = 1;
        dr16.remote_.wheel_ = 1024;
    }

    //裁判系统断联处理
    if (referee_is_offline) {
        //@developing...
    }
}

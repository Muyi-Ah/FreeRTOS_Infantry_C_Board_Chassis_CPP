#pragma once
#include "config.hpp"

class ErrorHandle {
   public:
    bool motor_is_offline[kMotorCount];  //电机掉线标志
    bool communication_is_offline;       //板间通信掉线标志
    bool referee_is_offline;             //裁判系统通信掉线标志

    void Check();
    void Handle();
};

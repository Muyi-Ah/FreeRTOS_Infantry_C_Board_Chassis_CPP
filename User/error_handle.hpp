#pragma once
#include "config.hpp"

class ErrorHandle {
   public:
    bool motor_is_offline[kMotorCount];  //������߱�־
    bool communication_is_offline;       //���ͨ�ŵ��߱�־
    bool referee_is_offline;             //����ϵͳͨ�ŵ��߱�־

    void Check();
    void Handle();
};

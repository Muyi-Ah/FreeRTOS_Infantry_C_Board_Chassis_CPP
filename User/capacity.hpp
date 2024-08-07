#pragma once
#include <cstdint>

class Capacity {
   public:
    float voltage = 0;
    float target_power = 0;
    uint16_t charge_power = 4500;  //Ĭ��45��
    bool is_reply_ = false;

    void EnableOutput();
    void SetMaxChargePower(uint16_t more_power);
    void AskVoltage();
    void AskInputPower();

    void Ask_RCIA();
    void SetMaxChargePower_RCIA();
};
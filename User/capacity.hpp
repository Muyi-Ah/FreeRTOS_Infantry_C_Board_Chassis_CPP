#pragma once
#include <cstdint>

class Capacity {
   public:
    float voltage = 0;
    float target_power = 0;
    uint16_t charge_power = 4500;  //Ä¬ÈÏ45Íß
    bool is_reply_ = false;

    void EnableOutput();
    void SetMaxChargePower();
    void AskVoltage();
    void AskInputPower();

    void Ask_RCIA();
    void SetMaxChargePower_RCIA();
};
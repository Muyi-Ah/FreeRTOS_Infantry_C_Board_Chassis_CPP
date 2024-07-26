#pragma once
#include <cstdint>
#include "cmsis_armclang.h"
#include "uart.hpp"

constexpr auto kFrameHeaderLength = 5;
constexpr auto kCmdIdLength = 2;
constexpr auto kFrameTailLength = 2;

__PACKED_STRUCT robot_status_t {
    uint8_t robot_id;
    uint8_t robot_level;
    uint16_t current_HP;
    uint16_t maximum_HP;
    uint16_t shooter_barrel_cooling_value;
    uint16_t shooter_barrel_heat_limit;
    uint16_t chassis_power_limit;
    uint8_t power_management_gimbal_output : 1;
    uint8_t power_management_chassis_output : 1;
    uint8_t power_management_shooter_output : 1;
};

__PACKED_STRUCT power_heat_data_t {
    uint16_t chassis_voltage;
    uint16_t chassis_current;
    float chassis_power;
    uint16_t buffer_energy;
    uint16_t shooter_17mm_1_barrel_heat;
    uint16_t shooter_17mm_2_barrel_heat;
    uint16_t shooter_42mm_barrel_heat;
};

__PACKED_STRUCT hurt_data_t {
    uint8_t armor_id : 4;
    uint8_t HP_deduction_reason : 4;
};

__PACKED_STRUCT frame_header {
    uint8_t SOF;
    uint16_t data_length;
    uint8_t seq;
    uint8_t CRC8;
};

__PACKED_STRUCT frame_tail {
    uint16_t CRC16;
};

class Referee {
   public:
    uint16_t recv_size;
    frame_header header;
    uint16_t cmd_id;

    robot_status_t robot_status;
    power_heat_data_t power_heat_data;
    hurt_data_t hurt_data;

    void FrameProcessing(uint8_t* buf);

   private:
};
#pragma once
#include "can.h"

constexpr CAN_HandleTypeDef* kMotorCan = &hcan1;
constexpr CAN_HandleTypeDef* kCapacityCan = &hcan2;

void CanInit();

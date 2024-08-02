#pragma once
#include "dji_motor.hpp"
#include "dr16.hpp"
#include "pid.hpp"
#include "state_machine.hpp"
#include "tracking_differentiator.hpp"
#include "capacity.hpp"
#include "communication.hpp"
#include "capacity.hpp"
#include "referee.hpp"
#include "ui.hpp"
#include "error_handle.hpp"
#include "config.hpp"

extern DR16 dr16;
extern DjiMotor motor_201;
extern DjiMotor motor_202;
extern DjiMotor motor_203;
extern DjiMotor motor_204;
extern DjiMotor* dji_motor_list[kMotorCount];

extern TD td_201;
extern TD td_202;
extern TD td_203;
extern TD td_204;

extern PID pid_vel_201;
extern PID pid_vel_202;
extern PID pid_vel_203;
extern PID pid_vel_204;

extern StateMachine state_machine;
extern Capacity capacity;
extern Communicator comm;
extern Referee referee;
extern ErrorHandle error_handle;

extern UILayerDelete UIDelete;
extern UIcharacterFigure const_character_voltage;
extern UIcharacterFigure const_character_maxrpm;
extern UIcharacterFigure const_character_level;
extern UIcharacterFigure const_character_powerlimit;
extern UIcharacterFigure const_character_visionmode;
extern UIcharacterFigure const_character_friction;
extern UIcharacterFigure character_chassis_mode;
extern UIFiveFigure var;
extern UIOneFigure oneline;
extern UIOneFigure twoline;
extern UITwoFigure chassis_angle_figure;
extern UIOneFigure vision_aimed;
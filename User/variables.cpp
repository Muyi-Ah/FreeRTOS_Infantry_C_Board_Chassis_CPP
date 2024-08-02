#include "variables.hpp"

DjiMotor motor_201(0x201);  //驱动轮
DjiMotor motor_202(0x202);  //驱动轮
DjiMotor motor_203(0x203);  //驱动轮
DjiMotor motor_204(0x204);  //驱动轮
//电机数组
DjiMotor* dji_motor_list[kMotorCount] = {
    &motor_201,
    &motor_202,
    &motor_203,
    &motor_204,
};

//微分跟踪器 用于电机速度滤波
TD td_201(200, 0.001);
TD td_202(200, 0.001);
TD td_203(200, 0.001);
TD td_204(200, 0.001);

PID pid_vel_201(8, 0, 0, 0, 16384);  //驱动轮速度环
PID pid_vel_202(8, 0, 0, 0, 16384);  //驱动轮速度环
PID pid_vel_203(8, 0, 0, 0, 16384);  //驱动轮速度环
PID pid_vel_204(8, 0, 0, 0, 16384);  //驱动轮速度环

DR16 dr16;                   //遥控器接收机
StateMachine state_machine;  //状态机
Capacity capacity;           //超级电容
Communicator comm;           //板间通信
Referee referee;             //裁判系统
ErrorHandle error_handle;    //错误处理

//UI
UILayerDelete UIDelete(103, 0x167);
UIcharacterFigure const_character_voltage(103, 0x167);
UIcharacterFigure const_character_maxrpm(103, 0x167);
UIcharacterFigure const_character_level(103, 0x167);
UIcharacterFigure const_character_powerlimit(103, 0x167);
UIcharacterFigure const_character_visionmode(103, 0x167);
UIcharacterFigure const_character_friction;
UIcharacterFigure character_chassis_mode;
UIFiveFigure var(103, 0x167);
UIOneFigure oneline;
UITwoFigure chassis_angle_figure;
UIOneFigure vision_aimed;
UISevenFigure aimed_line;
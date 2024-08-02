#include "variables.hpp"

DjiMotor motor_201(0x201);  //������
DjiMotor motor_202(0x202);  //������
DjiMotor motor_203(0x203);  //������
DjiMotor motor_204(0x204);  //������
//�������
DjiMotor* dji_motor_list[kMotorCount] = {
    &motor_201,
    &motor_202,
    &motor_203,
    &motor_204,
};

//΢�ָ����� ���ڵ���ٶ��˲�
TD td_201(200, 0.001);
TD td_202(200, 0.001);
TD td_203(200, 0.001);
TD td_204(200, 0.001);

PID pid_vel_201(8, 0, 0, 0, 16384);  //�������ٶȻ�
PID pid_vel_202(8, 0, 0, 0, 16384);  //�������ٶȻ�
PID pid_vel_203(8, 0, 0, 0, 16384);  //�������ٶȻ�
PID pid_vel_204(8, 0, 0, 0, 16384);  //�������ٶȻ�

DR16 dr16;                   //ң�������ջ�
StateMachine state_machine;  //״̬��
Capacity capacity;           //��������
Communicator comm;           //���ͨ��
Referee referee;             //����ϵͳ
ErrorHandle error_handle;    //������

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
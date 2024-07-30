#include "chassis_angle_figure.hpp"
#include <cstring>
#include "ui.hpp"
#include "variables.hpp"

interaction_figure_t chassis_angle_figure1;
interaction_figure_t chassis_angle_figure2;

int32_t start_angle1;
int32_t start_angle2;
int32_t end_angle1;
int32_t end_angle2;

void chassis_angle_figure_add_config() {
    chassis_angle_figure1.figure_name[0] = 2;
    chassis_angle_figure1.figure_name[1] = 0;
    chassis_angle_figure1.figure_name[2] = 0;
    chassis_angle_figure1.operate_tpye = kAddOperate;
    chassis_angle_figure1.figure_tpye = kArc;
    chassis_angle_figure1.layer = 2;
    chassis_angle_figure1.color = kCyan;
    chassis_angle_figure1.details_a = 45;   //起始角度
    chassis_angle_figure1.details_b = 315;  //终止角度
    chassis_angle_figure1.width = 8;
    // chassis_angle_figure1.start_x = 780;   //x位置
    // chassis_angle_figure1.start_y = 180;   //y位置
    chassis_angle_figure1.start_x = 650;   //x位置
    chassis_angle_figure1.start_y = 100;   //y位置
    chassis_angle_figure1.details_c = 0;   //无效
    chassis_angle_figure1.details_d = 40;  //x半轴长度
    chassis_angle_figure1.details_e = 40;  //y半轴长度

    chassis_angle_figure2.figure_name[0] = 2;
    chassis_angle_figure2.figure_name[1] = 0;
    chassis_angle_figure2.figure_name[2] = 1;
    chassis_angle_figure2.operate_tpye = kAddOperate;
    chassis_angle_figure2.figure_tpye = kArc;
    chassis_angle_figure2.layer = 2;
    chassis_angle_figure2.color = kPink;
    chassis_angle_figure2.details_a = 315;  //起始角度
    chassis_angle_figure2.details_b = 45;   //终止角度
    chassis_angle_figure2.width = 8;
    chassis_angle_figure2.start_x = 650;   //x位置
    chassis_angle_figure2.start_y = 100;   //y位置
    chassis_angle_figure2.details_c = 0;   //无效
    chassis_angle_figure2.details_d = 40;  //x半轴长度
    chassis_angle_figure2.details_e = 40;  //y半轴长度
}

#define MOD360(x) ((x) > 360 ? ((x) % 360) : (x))

void chassis_angle_figure_update_config() {
    start_angle1 = 45 + (360 - (uint16_t)comm.theta);
    end_angle1 = 315 + (360 - (uint16_t)comm.theta);
    start_angle1 = MOD360(start_angle1);
    end_angle1 = MOD360(end_angle1);

    chassis_angle_figure1.details_a = start_angle1;  //起始角度
    chassis_angle_figure1.details_b = end_angle1;    //终止角度
    chassis_angle_figure1.operate_tpye = kUpdateOperate;

    start_angle2 = 315 + (360 - (uint16_t)comm.theta);
    end_angle2 = 45 + (360 - (uint16_t)comm.theta);
    start_angle2 = MOD360(start_angle2);
    end_angle2 = MOD360(end_angle2);

    chassis_angle_figure2.details_a = start_angle2;  //起始角度
    chassis_angle_figure2.details_b = end_angle2;    //终止角度
    chassis_angle_figure2.operate_tpye = kUpdateOperate;
}

void chassis_angle_figure_delete_config() {
    chassis_angle_figure1.operate_tpye = kDeleteOperate;
    chassis_angle_figure2.operate_tpye = kDeleteOperate;
}
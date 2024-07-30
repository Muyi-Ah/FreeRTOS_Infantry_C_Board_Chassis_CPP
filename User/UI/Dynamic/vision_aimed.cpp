#include "vision_aimed.hpp"

interaction_figure_t vision_aimed_figure;

void vision_aimed_figure_add_config() {
    vision_aimed_figure.figure_name[0] = 2;
    vision_aimed_figure.figure_name[1] = 0;
    vision_aimed_figure.figure_name[2] = 4;
    vision_aimed_figure.operate_tpye = kAddOperate;
    vision_aimed_figure.figure_tpye = kRect;
    vision_aimed_figure.layer = 2;
    vision_aimed_figure.color = kCyan;
    vision_aimed_figure.width = 3;
    vision_aimed_figure.start_x = 570;     //x位置
    vision_aimed_figure.start_y = 180;     //y位置
    vision_aimed_figure.details_d = 1350;  //对角x位置
    vision_aimed_figure.details_e = 820;   //对角y位置
}

void vision_aimed_figure_update_is_aimed_config() {
    vision_aimed_figure.operate_tpye = kUpdateOperate;
    vision_aimed_figure.color = kPink;
}

void vision_aimed_figure_update_not_aimed_config() {
    vision_aimed_figure.operate_tpye = kUpdateOperate;
    vision_aimed_figure.color = kCyan;
}

void vision_aimed_figure_delete_config() {
    vision_aimed_figure.operate_tpye = kDeleteOperate;
}
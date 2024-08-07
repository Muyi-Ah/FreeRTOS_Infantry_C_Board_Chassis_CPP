/**
 * @file chassis_follow_mode.cpp
 * @author XMX
 * @brief 底盘跟随模式UI
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "chassis_follow_mode.hpp"
#include <cstring>

interaction_figure_t char_chassis_follow;

/// @brief 底盘模式UI添加
/// @param buf 字符数组
void char_chassis_follow_add_config(char* buf) {
    char_chassis_follow.figure_name[0] = 2;
    char_chassis_follow.figure_name[1] = 0;
    char_chassis_follow.figure_name[2] = 3;
    char_chassis_follow.operate_tpye = kAddOperate;
    char_chassis_follow.figure_tpye = kText;
    char_chassis_follow.layer = 2;
    char_chassis_follow.color = kPink;
    char_chassis_follow.details_a = 25;
    char_chassis_follow.details_b = 14;
    char_chassis_follow.width = 2;
    char_chassis_follow.start_x = 780;
    char_chassis_follow.start_y = 250-30;
    strcpy(buf, "chassis:normal");
}

/// @brief 底盘模式UI更新为不跟随
/// @param buf 字符数组
void char_chassis_update_Normal_config(char* buf) {
    char_chassis_follow.operate_tpye = kUpdateOperate;
    char_chassis_follow.color = kPink;
    char_chassis_follow.details_b = 14;
    strcpy(buf, "chassis:normal");
}

/// @brief 底盘模式UI更新为跟随
/// @param buf 字符数组
void char_chassis_update_Follow_config(char* buf) {
    char_chassis_follow.operate_tpye = kUpdateOperate;
    char_chassis_follow.color = kGreen;
    char_chassis_follow.details_b = 14;
    strcpy(buf, "chassis:follow");
}

/// @brief 底盘模式UI更新为旋转
/// @param buf 字符数组
void char_chassis_update_Rotate_config(char* buf) {
    char_chassis_follow.operate_tpye = kUpdateOperate;
    char_chassis_follow.color = kOrange;
    char_chassis_follow.details_b = 14;
    strcpy(buf, "chassis:rotate");
}

/// @brief 底盘模式UI删除
void char_chassis_delete_config() {
    char_chassis_follow.operate_tpye = kDeleteOperate;
}
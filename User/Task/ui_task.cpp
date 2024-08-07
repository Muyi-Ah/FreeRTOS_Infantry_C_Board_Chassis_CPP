/**
 * @file ui_task.cpp
 * @author XMX
 * @brief 客户端UI绘制任务
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ui_task.hpp"
#include "aimed_line.hpp"
#include "char_friction.hpp"
#include "char_level.hpp"
#include "char_maxrpm.hpp"
#include "char_powerlimit.hpp"
#include "char_visionmode.hpp"
#include "char_voltage.hpp"
#include "chassis.hpp"
#include "chassis_angle_figure.hpp"
#include "chassis_follow_mode.hpp"
#include "cmsis_os2.h"
#include "value_level.hpp"
#include "value_maxrpm.hpp"
#include "value_powerlimit.hpp"
#include "value_visionmode.hpp"
#include "value_voltage.hpp"
#include "variables.hpp"
#include "vision_aimed.hpp"

static void UI_ID_Update();

constexpr uint32_t kDynamicPeriod = 35;  //ui发送间隔

/**
 * 别忘了在最下面有个函数是ID更新的，别忘记更新ID了，不然UI发不到的
 * 
 */

bool ui_test_flag;  //测试用
bool ctrl_latch;    //CTRL键锁存
bool dynamic_flag;  //动态更新标志位
bool delete_flag;   //删除标志位
extern bool follow_flag;
extern bool rotate_flag;

/// @brief UI任务
/// @param argument 
void UITask(void* argument) {
    for (;;) {
        //重置UI
        if (dr16.KeyBoard_.key_.CTRL_key && ctrl_latch == false) {

            UI_ID_Update();  //ID更新

            ctrl_latch = true;
            delete_flag = true;

            UIDelete.Config(kDeleteAll, 0);  //清除0图层
            UIDelete.Config(kDeleteAll, 1);  //清除1图层
            UIDelete.Send();
            osDelay(35);

        } else if (dr16.KeyBoard_.key_.CTRL_key == 0) {
            ctrl_latch = false;
        }

        //静态
        if (ui_test_flag == true || delete_flag == true) {

            delete_flag = false;

            const_aimed_line_add_config();
            aimed_line.Config(&const_aimed_line1, &const_aimed_line2, &const_aimed_line3,
                              &const_aimed_line4, &const_aimed_line5, &const_aimed_line6,
                              &const_aimed_line7);
            aimed_line.Send();

            osDelay(35);

            //VOLTAGE字符
            char_voltage_add_config(
                (char*)&const_character_voltage.robot_interaction_data.character);
            const_character_voltage.config(&char_voltage);
            const_character_voltage.Send();

            osDelay(35);  //延时

            //MAXRPM字符
            char_maxrpm_add_config((char*)&const_character_maxrpm.robot_interaction_data.character);
            const_character_maxrpm.config(&char_maxrpm);
            const_character_maxrpm.Send();

            osDelay(35);  //延时

            //LEVEL字符
            char_level_add_config((char*)&const_character_level.robot_interaction_data.character);
            const_character_level.config(&char_level);
            const_character_level.Send();

            osDelay(35);  //延时

            //POWER_LIMIT字符
            char_powerlimit_add_config(
                (char*)&const_character_powerlimit.robot_interaction_data.character);
            const_character_powerlimit.config(&char_powerlimit);
            const_character_powerlimit.Send();

            osDelay(35);

            //VISION_MODE字符
            char_visionmode_add_config(
                (char*)&const_character_visionmode.robot_interaction_data.character);
            const_character_visionmode.config(&char_visionmode);
            const_character_visionmode.Send();

            osDelay(35);

            //FRICTION字符
            char_friction_add_config(
                (char*)&const_character_friction.robot_interaction_data.character);
            const_character_friction.config(&char_friction);
            const_character_friction.Send();

            osDelay(35);

            //CHASSIS_MODE字符
            char_chassis_follow_add_config(
                (char*)&character_chassis_mode.robot_interaction_data.character);
            character_chassis_mode.config(&char_chassis_follow);
            character_chassis_mode.Send();

            osDelay(35);

            var_voltage_add_config();     //Voltage数值
            var_maxrpm_add_config();      //MaxRpm数值
            var_level_add_config();       //Level数值
            var_powerlimit_add_config();  //PowerLimit数值
            var_visionmode_add_config();  //VisionMode数值

            var.Config(&var_voltage, &var_maxrpm, &var_level, &var_powerlimit, &var_visionmode);
            var.Send();

            osDelay(35);

            //底盘方位指示
            chassis_angle_figure_add_config();
            chassis_angle_figure.Config(&chassis_angle_figure1, &chassis_angle_figure2);
            chassis_angle_figure.Send();

            osDelay(35);

            //视觉瞄准框
            vision_aimed_figure_add_config();
            vision_aimed.Config(&vision_aimed_figure);
            vision_aimed.Send();

            osDelay(35);

            ui_test_flag = false;
            dynamic_flag = true;
        }

        //动态
        if (dynamic_flag) {
            var_voltage_update_config(capacity.voltage * 1000);  //Voltage数值
            //最大转速调整判断
            if (adjust_max_rpm_flag) {
                var_maxrpm_update_config(max_rpm, kOrange);  //MaxRpm数值
            } else {
                var_maxrpm_update_config(max_rpm, kCyan);  //MaxRpm数值
            }
            var_level_update_config(referee.robot_status.robot_level);  //Level数值
            var_powerlimit_update_config(
                referee.robot_status.chassis_power_limit);       //PowerLimit数值
            var_visionmode_update_config(comm.vision_aim_type);  //VisionMode数值

            var.Config(&var_voltage, &var_maxrpm, &var_level, &var_powerlimit, &var_visionmode);
            var.Send();

            osDelay(kDynamicPeriod);

            //底盘指示更新
            chassis_angle_figure_update_config();
            chassis_angle_figure.Config(&chassis_angle_figure1, &chassis_angle_figure2);
            chassis_angle_figure.Send();

            osDelay(kDynamicPeriod);

            //摩擦轮开关表示
            if (comm.friction_is_enable == 0) {
                char_friction_update_OFF_config(
                    (char*)&const_character_friction.robot_interaction_data.character);
                const_character_friction.config(&char_friction);
                const_character_friction.Send();

                osDelay(kDynamicPeriod);
            } else {
                char_friction_update_ON_config(
                    (char*)&const_character_friction.robot_interaction_data.character);
                const_character_friction.config(&char_friction);
                const_character_friction.Send();

                osDelay(kDynamicPeriod);
            }

            //视觉锁定状态表示
            if (comm.vision_is_aimed) {
                vision_aimed_figure_update_is_aimed_config();
                vision_aimed.Config(&vision_aimed_figure);
                vision_aimed.Send();

                osDelay(kDynamicPeriod);
            } else {
                vision_aimed_figure_update_not_aimed_config();
                vision_aimed.Config(&vision_aimed_figure);
                vision_aimed.Send();

                osDelay(kDynamicPeriod);
            }

            //底盘跟随模式表示
            if (rotate_flag) {
                char_chassis_update_Rotate_config(
                    (char*)&character_chassis_mode.robot_interaction_data.character);
                character_chassis_mode.config(&char_chassis_follow);
                character_chassis_mode.Send();

                osDelay(kDynamicPeriod);
            } else if (follow_flag) {
                char_chassis_update_Follow_config(
                    (char*)&character_chassis_mode.robot_interaction_data.character);
                character_chassis_mode.config(&char_chassis_follow);
                character_chassis_mode.Send();

                osDelay(kDynamicPeriod);
            } else {
                char_chassis_update_Normal_config(
                    (char*)&character_chassis_mode.robot_interaction_data.character);
                character_chassis_mode.config(&char_chassis_follow);
                character_chassis_mode.Send();

                osDelay(kDynamicPeriod);
            }
        }
    }
}

/// @brief 机器人ID获取
/// @return 
static uint16_t GetRobotID() {
    return referee.robot_status.robot_id;
}

/// @brief 机器人对应客户端ID获取
/// @return 
static uint16_t GetClientID() {
    return referee.robot_status.robot_id + 0x100;
}

/// @brief UI发送/接收ID更新
static void UI_ID_Update() {
    uint16_t sender_id = GetRobotID();
    uint16_t receiver_id = GetClientID();
    UIDelete.SetID(sender_id, receiver_id);
    const_character_voltage.SetID(sender_id, receiver_id);
    const_character_maxrpm.SetID(sender_id, receiver_id);
    const_character_level.SetID(sender_id, receiver_id);
    const_character_powerlimit.SetID(sender_id, receiver_id);
    const_character_visionmode.SetID(sender_id, receiver_id);
    var.SetID(sender_id, receiver_id);
    oneline.SetID(sender_id, receiver_id);
    const_character_friction.SetID(sender_id, receiver_id);
    chassis_angle_figure.SetID(sender_id, receiver_id);
    vision_aimed.SetID(sender_id, receiver_id);
    character_chassis_mode.SetID(sender_id, receiver_id);
    aimed_line.SetID(sender_id, receiver_id);
}
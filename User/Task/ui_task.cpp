#include "ui_task.hpp"
#include "char_level.hpp"
#include "char_maxrpm.hpp"
#include "char_powerlimit.hpp"
#include "char_visionmode.hpp"
#include "char_voltage.hpp"
#include "chassis.hpp"
#include "cmsis_os2.h"
#include "value_level.hpp"
#include "value_maxrpm.hpp"
#include "value_powerlimit.hpp"
#include "value_visionmode.hpp"
#include "value_voltage.hpp"
#include "variables.hpp"

static void UI_ID_Update();

interaction_figure_t interaction_figure_oneline = {"on", 1, 0, 2, 6, 0, 0, 5, 0, 512, 0, 1920, 512};

bool ui_test_flag;  //������
bool ctrl_latch;
bool dynamic_flag;
bool delete_flag;
void UITask(void* argument) {
    for (;;) {
        //����UI
        if (dr16.KeyBoard_.key_.CTRL_key && ctrl_latch == false) {

            UI_ID_Update();  //ID����

            ctrl_latch = true;
            delete_flag = true;

            UIDelete.Config(kDeleteAll, 0);  //���0ͼ��
            UIDelete.Config(kDeleteAll, 1);  //���1ͼ��
            UIDelete.Send();
            osDelay(100);

        } else if (dr16.KeyBoard_.key_.CTRL_key == 0) {
            ctrl_latch = false;
        }

        //��̬
        if (ui_test_flag == true || delete_flag == true) {

            delete_flag = false;

            oneline.Config(&interaction_figure_oneline);
            oneline.Send();

            osDelay(100);

            //VOLTAGE�ַ�
            char_voltage_add_config(
                (char*)&const_character_voltage.robot_interaction_data.character);
            const_character_voltage.config(&char_voltage);
            const_character_voltage.Send();

            osDelay(100);  //��ʱ

            //MAXRPM�ַ�
            char_maxrpm_add_config((char*)&const_character_maxrpm.robot_interaction_data.character);
            const_character_maxrpm.config(&char_maxrpm);
            const_character_maxrpm.Send();

            osDelay(100);  //��ʱ

            //LEVEL�ַ�
            char_level_add_config((char*)&const_character_level.robot_interaction_data.character);
            const_character_level.config(&char_level);
            const_character_level.Send();

            osDelay(100);  //��ʱ

            //POWER_LIMIT�ַ�
            char_powerlimit_add_config(
                (char*)&const_character_powerlimit.robot_interaction_data.character);
            const_character_powerlimit.config(&char_powerlimit);
            const_character_powerlimit.Send();

            osDelay(100);

            //VISION_MODE�ַ�
            char_visionmode_add_config(
                (char*)&const_character_visionmode.robot_interaction_data.character);
            const_character_visionmode.config(&char_visionmode);
            const_character_visionmode.Send();

            osDelay(100);

            var_voltage_add_config();     //Voltage��ֵ
            var_maxrpm_add_config();      //MaxRpm��ֵ
            var_level_add_config();       //Level��ֵ
            var_powerlimit_add_config();  //PowerLimit��ֵ
            var_visionmode_add_config();  //VisionMode��ֵ

            var.Config(&var_voltage, &var_maxrpm, &var_level, &var_powerlimit, &var_visionmode);
            var.Send();

            osDelay(100);

            ui_test_flag = false;
            dynamic_flag = true;
        }

        //��̬
        if (dynamic_flag) {
            var_voltage_update_config(capacity.voltage * 1000);         //Voltage��ֵ
            var_maxrpm_update_config(max_rpm);                          //MaxRpm��ֵ
            var_level_update_config(referee.robot_status.robot_level);  //Level��ֵ
            var_powerlimit_update_config(
                referee.robot_status.chassis_power_limit);       //PowerLimit��ֵ
            var_visionmode_update_config(comm.vision_aim_type);  //VisionMode��ֵ

            var.Config(&var_voltage, &var_maxrpm, &var_level, &var_powerlimit, &var_visionmode);
            var.Send();

            osDelay(100);
        }

        osDelay(10);
    }
}

static uint16_t GetRobotID() {
    return referee.robot_status.robot_id;
}

static uint16_t GetClientID() {
    return referee.robot_status.robot_id + 0x100;
}

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
}
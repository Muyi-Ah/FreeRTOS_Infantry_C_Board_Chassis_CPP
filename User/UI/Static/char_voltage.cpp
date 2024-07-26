#include "char_voltage.hpp"
#include <cstring>
#include "ui.hpp"

interaction_figure_t char_voltage;

void char_voltage_add_config(char* buf) {
    char_voltage.figure_name[0] = 0;
    char_voltage.figure_name[1] = 0;
    char_voltage.figure_name[2] = 0;
    char_voltage.operate_tpye = kAddOperate;
    char_voltage.figure_tpye = kText;
    char_voltage.layer = 0;
    char_voltage.color = kGreen;
    char_voltage.details_a = 30;
    char_voltage.details_b = 8;
    char_voltage.width = 3;
    char_voltage.start_x = 780;
    char_voltage.start_y = 150;
    strcpy(buf, "Voltage:");
}

void char_voltage_delete_config() {
    char_voltage.operate_tpye = kDeleteOperate;
}

#include "value_voltage.hpp"
#include "ui.hpp"

interaction_figure_t var_voltage;

void var_voltage_add_config() {
    var_voltage.figure_name[0] = 1;
    var_voltage.figure_name[1] = 0;
    var_voltage.figure_name[2] = 0;
    var_voltage.operate_tpye = kAddOperate;
    var_voltage.figure_tpye = kFloat;
    var_voltage.layer = 1;
    var_voltage.color = kCyan;
    var_voltage.details_a = 25;
    var_voltage.width = 2;
    var_voltage.start_x = 980;
    var_voltage.start_y = 200 - 40;
    var_voltage.details_c = 0;
    var_voltage.details_d = 0;
    var_voltage.details_e = 0;
}

void var_voltage_update_config(uint32_t var) {
    var_voltage.operate_tpye = kUpdateOperate;
    var_voltage.details_c = (var >> 0) & 0x3FF;
    var_voltage.details_d = (var >> 10) & 0x7FF;
    var_voltage.details_e = (var >> 21) & 0x7FF;
}

void var_voltage_delete_config() {
    var_voltage.operate_tpye = kDeleteOperate;
}
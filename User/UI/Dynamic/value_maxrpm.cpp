#include "value_maxrpm.hpp"
#include "ui.hpp"

interaction_figure_t var_maxrpm;

void var_maxrpm_add_config() {
    var_maxrpm.figure_name[0] = 1;
    var_maxrpm.figure_name[1] = 0;
    var_maxrpm.figure_name[2] = 1;
    var_maxrpm.operate_tpye = kAddOperate;
    var_maxrpm.figure_tpye = kNumber;
    var_maxrpm.layer = 1;
    var_maxrpm.color = kCyan;
    var_maxrpm.details_a = 25;
    var_maxrpm.width = 2;
    var_maxrpm.start_x = 400;
    var_maxrpm.start_y = 650;
    var_maxrpm.details_c = 0;
    var_maxrpm.details_d = 0;
    var_maxrpm.details_e = 0;
}

void var_maxrpm_update_config(uint32_t var, int color) {
    var_maxrpm.color = color;
    var_maxrpm.operate_tpye = kUpdateOperate;
    var_maxrpm.details_c = (var >> 0) & 0x3FF;
    var_maxrpm.details_d = (var >> 10) & 0x7FF;
    var_maxrpm.details_e = (var >> 21) & 0x7FF;
}

void var_maxrpm_delete_config() {
    var_maxrpm.operate_tpye = kDeleteOperate;
}
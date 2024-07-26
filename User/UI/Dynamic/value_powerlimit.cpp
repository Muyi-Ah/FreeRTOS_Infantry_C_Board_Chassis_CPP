#include "value_powerlimit.hpp"
#include "ui.hpp"

interaction_figure_t var_powerlimit;

void var_powerlimit_add_config() {
    var_powerlimit.figure_name[0] = 1;
    var_powerlimit.figure_name[1] = 0;
    var_powerlimit.figure_name[2] = 3;
    var_powerlimit.operate_tpye = kAddOperate;
    var_powerlimit.figure_tpye = kNumber;
    var_powerlimit.layer = 1;
    var_powerlimit.color = kCyan;
    var_powerlimit.details_a = 30;
    var_powerlimit.width = 3;
    var_powerlimit.start_x = 270;
    var_powerlimit.start_y = 590;
    var_powerlimit.details_c = 0;
    var_powerlimit.details_d = 0;
    var_powerlimit.details_e = 0;
}

void var_powerlimit_update_config(uint32_t var) {
    var_powerlimit.operate_tpye = kUpdateOperate;
    var_powerlimit.details_c = (var >> 0) & 0x3FF;
    var_powerlimit.details_d = (var >> 10) & 0x7FF;
    var_powerlimit.details_e = (var >> 21) & 0x7FF;
}

void var_powerlimit_delete_config() {
    var_powerlimit.operate_tpye = kDeleteOperate;
}
#include "value_visionmode.hpp"
#include "ui.hpp"

interaction_figure_t var_visionmode;

void var_visionmode_add_config() {
    var_visionmode.figure_name[0] = 1;
    var_visionmode.figure_name[1] = 0;
    var_visionmode.figure_name[2] = 4;
    var_visionmode.operate_tpye = kAddOperate;
    var_visionmode.figure_tpye = kNumber;
    var_visionmode.layer = 1;
    var_visionmode.color = kCyan;
    var_visionmode.details_a = 30;
    var_visionmode.width = 3;
    var_visionmode.start_x = 950;
    var_visionmode.start_y = 220;
    var_visionmode.details_c = 0;
    var_visionmode.details_d = 0;
    var_visionmode.details_e = 0;
}

void var_visionmode_update_config(uint32_t var) {
    var_visionmode.operate_tpye = kUpdateOperate;
    var_visionmode.details_c = (var >> 0) & 0x3FF;
    var_visionmode.details_d = (var >> 10) & 0x7FF;
    var_visionmode.details_e = (var >> 21) & 0x7FF;
}

void var_visionmode_delete_config() {
    var_visionmode.operate_tpye = kDeleteOperate;
}
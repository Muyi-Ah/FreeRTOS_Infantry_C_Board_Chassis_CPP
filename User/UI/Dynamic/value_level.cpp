#include "value_level.hpp"
#include <cstring>
#include "ui.hpp"

interaction_figure_t var_level;

void var_level_add_config() {
    var_level.figure_name[0] = 1;
    var_level.figure_name[1] = 0;
    var_level.figure_name[2] = 2;
    var_level.operate_tpye = kAddOperate;
    var_level.figure_tpye = kNumber;
    var_level.layer = 1;
    var_level.color = kCyan;
    var_level.details_a = 25;
    var_level.width = 2;
    var_level.start_x = 400;
    var_level.start_y = 750;
    var_level.details_c = 0;
    var_level.details_d = 0;
    var_level.details_e = 0;
}

void var_level_update_config(uint32_t var) {
    var_level.operate_tpye = kUpdateOperate;
    var_level.details_c = (var >> 0) & 0x3FF;
    var_level.details_d = (var >> 10) & 0x7FF;
    var_level.details_e = (var >> 21) & 0x7FF;
}

void var_level_delete_config() {
    var_level.operate_tpye = kDeleteOperate;
}
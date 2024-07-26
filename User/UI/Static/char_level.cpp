#include "char_level.hpp"
#include <cstring>
#include "ui.hpp"

interaction_figure_t char_level;

void char_level_add_config(char* buf) {
    char_level.figure_name[0] = 0;
    char_level.figure_name[1] = 0;
    char_level.figure_name[2] = 2;
    char_level.operate_tpye = kAddOperate;
    char_level.figure_tpye = kText;
    char_level.layer = 0;
    char_level.color = kGreen;
    char_level.details_a = 30;
    char_level.details_b = 6;
    char_level.width = 3;
    char_level.start_x = 90;
    char_level.start_y = 800;
    strcpy(buf, "Level:");
}

void char_level_delete_config() {
    char_level.operate_tpye = kDeleteOperate;
}
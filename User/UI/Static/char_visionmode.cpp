#include "char_visionmode.hpp"
#include <cstring>
#include "ui.hpp"

interaction_figure_t char_visionmode;

void char_visionmode_add_config(char* buf) {
    char_visionmode.figure_name[0] = 0;
    char_visionmode.figure_name[1] = 0;
    char_visionmode.figure_name[2] = 4;
    char_visionmode.operate_tpye = kAddOperate;
    char_visionmode.figure_tpye = kText;
    char_visionmode.layer = 0;
    char_visionmode.color = kGreen;
    char_visionmode.details_a = 25;
    char_visionmode.details_b = 5;
    char_visionmode.width = 2;
    char_visionmode.start_x = 780;
    char_visionmode.start_y = 100 - 40;
    strcpy(buf, "Mode:");
}

void char_visionmode_delete_config() {
    char_visionmode.operate_tpye = kDeleteOperate;
}
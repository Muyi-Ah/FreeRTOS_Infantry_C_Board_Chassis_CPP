#include "char_powerlimit.hpp"
#include <cstring>
#include "ui.hpp"

interaction_figure_t char_powerlimit;

void char_powerlimit_add_config(char* buf) {
    char_powerlimit.figure_name[0] = 0;
    char_powerlimit.figure_name[1] = 0;
    char_powerlimit.figure_name[2] = 3;
    char_powerlimit.operate_tpye = kAddOperate;
    char_powerlimit.figure_tpye = kText;
    char_powerlimit.layer = 0;
    char_powerlimit.color = kGreen;
    char_powerlimit.details_a = 25;
    char_powerlimit.details_b = 6;
    char_powerlimit.width = 2;
    char_powerlimit.start_x = 230;
    char_powerlimit.start_y = 700;
    strcpy(buf, "Power:");
}

void char_powerlimit_delete_config() {
    char_powerlimit.operate_tpye = kDeleteOperate;
}
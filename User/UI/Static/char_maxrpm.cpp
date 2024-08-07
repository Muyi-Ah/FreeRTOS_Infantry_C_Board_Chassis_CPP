#include "char_maxrpm.hpp"
#include <cstring>
#include "ui.hpp"

interaction_figure_t char_maxrpm;

void char_maxrpm_add_config(char* buf) {
    char_maxrpm.figure_name[0] = 0;
    char_maxrpm.figure_name[1] = 0;
    char_maxrpm.figure_name[2] = 1;
    char_maxrpm.operate_tpye = kAddOperate;
    char_maxrpm.figure_tpye = kText;
    char_maxrpm.layer = 0;
    char_maxrpm.color = kGreen;
    char_maxrpm.details_a = 25;
    char_maxrpm.details_b = 7;
    char_maxrpm.width = 2;
    char_maxrpm.start_x = 230;
    char_maxrpm.start_y = 650;
    strcpy(buf, "Maxrpm:");
}

void char_maxrpm_delete_config() {
    char_maxrpm.operate_tpye = kDeleteOperate;
}
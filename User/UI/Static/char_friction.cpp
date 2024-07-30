#include "char_friction.hpp"
#include <cstring>

interaction_figure_t char_friction;

void char_friction_add_config(char* buf) {
    char_friction.figure_name[0] = 2;
    char_friction.figure_name[1] = 0;
    char_friction.figure_name[2] = 2;
    char_friction.operate_tpye = kAddOperate;
    char_friction.figure_tpye = kText;
    char_friction.layer = 2;
    char_friction.color = kGreen;
    char_friction.details_a = 25;
    char_friction.details_b = 12;
    char_friction.width = 2;
    char_friction.start_x = 780;
    char_friction.start_y = 150 - 40;
    strcpy(buf, "Friction:OFF");
}

void char_friction_update_ON_config(char* buf) {
    char_friction.operate_tpye = kUpdateOperate;
    char_friction.color = kGreen;
    char_friction.details_b = 11;
    strcpy(buf, "Friction:ON");
}

void char_friction_update_OFF_config(char* buf) {
    char_friction.operate_tpye = kUpdateOperate;
    char_friction.color = kPink;
    char_friction.details_b = 12;
    strcpy(buf, "Friction:OFF");
}

void char_friction_delete_config() {
    char_friction.operate_tpye = kDeleteOperate;
}
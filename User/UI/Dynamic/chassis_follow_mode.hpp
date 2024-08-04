#pragma once
#include "ui.hpp"

extern interaction_figure_t char_chassis_follow;

void char_chassis_follow_add_config(char* buf);
void char_chassis_update_Normal_config(char* buf);
void char_chassis_update_Follow_config(char* buf);
void char_chassis_update_Rotate_config(char* buf);
void char_chassis_delete_config();
#pragma once
#include "ui.hpp"

extern interaction_figure_t char_friction;

void char_friction_add_config(char* buf);
void char_friction_update_ON_config(char* buf);
void char_friction_update_OFF_config(char* buf);
void char_friction_delete_config();
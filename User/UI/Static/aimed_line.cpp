#include "aimed_line.hpp"

interaction_figure_t const_aimed_line1;
interaction_figure_t const_aimed_line2;
interaction_figure_t const_aimed_line3;
interaction_figure_t const_aimed_line4;
interaction_figure_t const_aimed_line5;
interaction_figure_t const_aimed_line6;
interaction_figure_t const_aimed_line7;

auto offset_x = 0;
auto offset_y = 0;

void const_aimed_line_add_config() {
    const_aimed_line1.figure_name[0] = 3;
    const_aimed_line1.figure_name[1] = 0;
    const_aimed_line1.figure_name[2] = 0;
    const_aimed_line1.operate_tpye = kAddOperate;
    const_aimed_line1.figure_tpye = kLine;
    const_aimed_line1.layer = 3;
    const_aimed_line1.color = kCyan;
    const_aimed_line1.width = 2;
    const_aimed_line1.start_x = 960 + offset_x;    //xÎ»ÖÃ
    const_aimed_line1.start_y = 600 + offset_y;    //yÎ»ÖÃ
    const_aimed_line1.details_d = 960 + offset_x;  //ÖÕÖ¹xÎ»ÖÃ
    const_aimed_line1.details_e = 475 + offset_y;  //ÖÕÖ¹yÎ»ÖÃ

    const_aimed_line2.figure_name[0] = 3;
    const_aimed_line2.figure_name[1] = 0;
    const_aimed_line2.figure_name[2] = 1;
    const_aimed_line2.operate_tpye = kAddOperate;
    const_aimed_line2.figure_tpye = kLine;
    const_aimed_line2.layer = 3;
    const_aimed_line2.color = kCyan;
    const_aimed_line2.width = 2;
    const_aimed_line2.start_x = 960 - 10 + offset_x;    //xÎ»ÖÃ
    const_aimed_line2.start_y = 537 + offset_y;         //yÎ»ÖÃ
    const_aimed_line2.details_d = 960 + 10 + offset_x;  //ÖÕÖ¹xÎ»ÖÃ
    const_aimed_line2.details_e = 537 + offset_y;       //ÖÕÖ¹yÎ»ÖÃ

    const_aimed_line3.figure_name[0] = 3;
    const_aimed_line3.figure_name[1] = 0;
    const_aimed_line3.figure_name[2] = 2;
    const_aimed_line3.operate_tpye = kAddOperate;
    const_aimed_line3.figure_tpye = kLine;
    const_aimed_line3.layer = 3;
    const_aimed_line3.color = kCyan;
    const_aimed_line3.width = 2;
    const_aimed_line3.start_x = 960 - 30 + offset_x;    //xÎ»ÖÃ
    const_aimed_line3.start_y = 600 + offset_y;         //yÎ»ÖÃ
    const_aimed_line3.details_d = 960 + 30 + offset_x;  //ÖÕÖ¹xÎ»ÖÃ
    const_aimed_line3.details_e = 600 + offset_y;       //ÖÕÖ¹yÎ»ÖÃx

    const_aimed_line4.figure_name[0] = 3;
    const_aimed_line4.figure_name[1] = 0;
    const_aimed_line4.figure_name[2] = 3;
    const_aimed_line4.operate_tpye = kAddOperate;
    const_aimed_line4.figure_tpye = kLine;
    const_aimed_line4.layer = 3;
    const_aimed_line4.color = kCyan;
    const_aimed_line4.width = 2;
    const_aimed_line4.start_x = 960 - 30 + offset_x;    //xÎ»ÖÃ
    const_aimed_line4.start_y = 475 + offset_y;         //yÎ»ÖÃ
    const_aimed_line4.details_d = 960 + 30 + offset_x;  //ÖÕÖ¹xÎ»ÖÃ
    const_aimed_line4.details_e = 475 + offset_y;       //ÖÕÖ¹yÎ»ÖÃ

    const_aimed_line5.figure_name[0] = 3;
    const_aimed_line5.figure_name[1] = 0;
    const_aimed_line5.figure_name[2] = 4;
    const_aimed_line5.operate_tpye = kAddOperate;
    const_aimed_line5.figure_tpye = kLine;
    const_aimed_line5.layer = 3;
    const_aimed_line5.color = kCyan;
    const_aimed_line5.width = 2;
    const_aimed_line5.start_x = 960 - 20 + offset_x;    //xÎ»ÖÃ
    const_aimed_line5.start_y = 568 + offset_y;         //yÎ»ÖÃ
    const_aimed_line5.details_d = 960 + 20 + offset_x;  //ÖÕÖ¹xÎ»ÖÃ
    const_aimed_line5.details_e = 568 + offset_y;       //ÖÕÖ¹yÎ»ÖÃ

    const_aimed_line6.figure_name[0] = 3;
    const_aimed_line6.figure_name[1] = 0;
    const_aimed_line6.figure_name[2] = 5;
    const_aimed_line6.operate_tpye = kAddOperate;
    const_aimed_line6.figure_tpye = kLine;
    const_aimed_line6.layer = 3;
    const_aimed_line6.color = kCyan;
    const_aimed_line6.width = 2;
    const_aimed_line6.start_x = 960 - 20 + offset_x;    //xÎ»ÖÃ
    const_aimed_line6.start_y = 507 + offset_y;         //yÎ»ÖÃ
    const_aimed_line6.details_d = 960 + 20 + offset_x;  //ÖÕÖ¹xÎ»ÖÃ
    const_aimed_line6.details_e = 507 + offset_y;       //ÖÕÖ¹yÎ»ÖÃ
}

void const_aimed_line_delete_config() {
    const_aimed_line1.operate_tpye = kDeleteOperate;
    const_aimed_line2.operate_tpye = kDeleteOperate;
}
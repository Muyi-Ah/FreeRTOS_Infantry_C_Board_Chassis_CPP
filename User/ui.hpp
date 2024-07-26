#pragma once
#include <cstdint>
#include "cmsis_armclang.h"
#include "referee.hpp"

constexpr auto kLayerDeleteSize = 2;
constexpr auto kOneFigureSize = 15;
constexpr auto kTwoFigureSize = 30;
constexpr auto kFiveFigureSize = 75;
constexpr auto kSevenFigureSize = 105;
constexpr auto kCharacterFigureSize = 15;

//  ============ UI图层操作 ===========
constexpr auto kNoneOperate = 0;
constexpr auto kAddOperate = 1;
constexpr auto kUpdateOperate = 2;
constexpr auto kDeleteOperate = 3;
//  ===================================

//  ============ UI图形类型 ===========
constexpr auto kLine = 0;
constexpr auto kRect = 1;
constexpr auto kRound = 2;
constexpr auto kEllipse = 3;
constexpr auto kArc = 4;
constexpr auto kFloat = 5;
constexpr auto kNumber = 6;
constexpr auto kText = 7;
//  ===================================

//  ============ UI图形颜色 ===========
constexpr auto kMine = 0;
constexpr auto kYellow = 1;
constexpr auto kGreen = 2;
constexpr auto kOrange = 3;
constexpr auto kPurple = 4;
constexpr auto kPink = 5;
constexpr auto kCyan = 6;
constexpr auto kBlack = 7;
constexpr auto kWhite = 8;
//  ===================================

enum InteractionType {
    kLayerDelete,
    kOneFigure,
    kTwoFigure,
    kFiveFigure,
    kSevenFigure,
    kcharacterFigure,
};

enum DeleteType {
    kNone_1,
    kDelete,
    kDeleteAll,
};

enum OperateType {
    kNone_2,
    kAdd,
    kAdjust,
    kDeleteLayer,
};

/**
 * @brief 图层删除
 * 
 */
__PACKED_STRUCT interaction_layer_delete_t {
    uint8_t delete_type;
    uint8_t layer;
};

/**
 * @brief 图形配置
 * 
 */
__PACKED_STRUCT interaction_figure_t {
    uint8_t figure_name[3];
    uint32_t operate_tpye : 3;
    uint32_t figure_tpye : 3;
    uint32_t layer : 4;
    uint32_t color : 4;
    uint32_t details_a : 9;
    uint32_t details_b : 9;
    uint32_t width : 10;
    uint32_t start_x : 11;
    uint32_t start_y : 11;
    uint32_t details_c : 10;
    uint32_t details_d : 11;
    uint32_t details_e : 11;
};

/**
 * @brief 两个图形
 * 
 */
__PACKED_STRUCT interaction_figure_2_t {
    interaction_figure_t interaction_figure[2];
};

/**
 * @brief 五个图形
 * 
 */
__PACKED_STRUCT interaction_figure_3_t {
    interaction_figure_t interaction_figure[5];
};

/**
 * @brief 七个图形
 * 
 */
__PACKED_STRUCT interaction_figure_4_t {
    interaction_figure_t interaction_figure[7];
};

/**
 * @brief 字符
 * 
 */
__PACKED_STRUCT interaction_character_t {
    interaction_figure_t interaction_figure;
    uint8_t data[30];
};

class UILayerDelete {
   public:
    UILayerDelete(uint16_t sender_id = 0x000, uint16_t receiver_id = 0x000);
    void SetID(uint16_t sender_id, uint16_t receiver_id) {
        robot_interaction_data.sender_id = sender_id;
        robot_interaction_data.receiver_id = receiver_id;
    };
    void Config(DeleteType type, uint8_t layer);
    void Send();

    frame_header header;
    const uint16_t cmd_id = 0x0301;

    __PACKED_STRUCT {
        uint16_t data_cmd_id;
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[kLayerDeleteSize];
    }
    robot_interaction_data;

    frame_tail tail;
};

class UIOneFigure {
   public:
    UIOneFigure(uint16_t sender_id = 0x000, uint16_t receiver_id = 0x000);
    void SetID(uint16_t sender_id, uint16_t receiver_id) {
        robot_interaction_data.sender_id = sender_id;
        robot_interaction_data.receiver_id = receiver_id;
    };
    void Config(interaction_figure_t* interaction_figure);
    void Send();

    frame_header header;
    uint16_t cmd_id = 0x0301;

    __PACKED_STRUCT {
        uint16_t data_cmd_id;
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[kOneFigureSize];
    }
    robot_interaction_data;

    frame_tail tail;
};

class UITwoFigure {
   public:
    UITwoFigure(uint16_t sender_id = 0x000, uint16_t receiver_id = 0x000);
    void SetID(uint16_t sender_id, uint16_t receiver_id) {
        robot_interaction_data.sender_id = sender_id;
        robot_interaction_data.receiver_id = receiver_id;
    };
    void Config(interaction_figure_t* interaction_figure1,
                interaction_figure_t* interaction_figure2);
    void Send();

    frame_header header;
    uint16_t cmd_id = 0x0301;

    __PACKED_STRUCT {
        uint16_t data_cmd_id;
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[kTwoFigureSize];
    }
    robot_interaction_data;

    frame_tail tail;
};

class UIFiveFigure {
   public:
    UIFiveFigure(uint16_t sender_id = 0x000, uint16_t receiver_id = 0x000);
    void SetID(uint16_t sender_id, uint16_t receiver_id) {
        robot_interaction_data.sender_id = sender_id;
        robot_interaction_data.receiver_id = receiver_id;
    };
    void Config(interaction_figure_t* interaction_figure1,
                interaction_figure_t* interaction_figure2,
                interaction_figure_t* interaction_figure3,
                interaction_figure_t* interaction_figure4,
                interaction_figure_t* interaction_figure5);
    void Send();

    frame_header header;
    uint16_t cmd_id = 0x0301;

    __PACKED_STRUCT {
        uint16_t data_cmd_id;
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[kFiveFigureSize];
    }
    robot_interaction_data;

    frame_tail tail;
};

class UISevenFigure {
   public:
    UISevenFigure(uint16_t sender_id = 0x000, uint16_t receiver_id = 0x000);
    void SetID(uint16_t sender_id, uint16_t receiver_id) {
        robot_interaction_data.sender_id = sender_id;
        robot_interaction_data.receiver_id = receiver_id;
    };
    void Config(interaction_figure_t* interaction_figure1,
                interaction_figure_t* interaction_figure2,
                interaction_figure_t* interaction_figure3,
                interaction_figure_t* interaction_figure4,
                interaction_figure_t* interaction_figure5,
                interaction_figure_t* interaction_figure6,
                interaction_figure_t* interaction_figure7);
    void Send();

    frame_header header;
    uint16_t cmd_id = 0x0301;

    __PACKED_STRUCT {
        uint16_t data_cmd_id;
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[kSevenFigureSize];
    }
    robot_interaction_data;

    frame_tail tail;
};

class UIcharacterFigure {
   public:
    UIcharacterFigure(uint16_t sender_id = 0x000, uint16_t receiver_id = 0x000);
    void SetID(uint16_t sender_id, uint16_t receiver_id) {
        robot_interaction_data.sender_id = sender_id;
        robot_interaction_data.receiver_id = receiver_id;
    };
    void config(interaction_figure_t* interaction_figure);
    void Send();

    frame_header header;
    uint16_t cmd_id = 0x0301;

    __PACKED_STRUCT {
        uint16_t data_cmd_id;
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[kCharacterFigureSize];
        char character[30]{0};
    }
    robot_interaction_data;

    frame_tail tail;
};

#include "ui.hpp"
#include <cstring>
#include "crc.hpp"

/**
 * @brief Construct a new UILayerDelete::UILayerDelete object
 * 
 * @param sender_id 发送者ID
 * @param receiver_id 接收者ID
 */
UILayerDelete::UILayerDelete(uint16_t sender_id, uint16_t receiver_id) {

    header.SOF = 0xA5;  //帧头固定为0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0100;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief 图形删除配置
 * 
 * @param str 名称
 * @param type 删除类型
 * @param layer 层数
 */
void UILayerDelete::Config(DeleteType type, uint8_t layer) {
    interaction_layer_delete_t* interaction_layer_delete =
        (interaction_layer_delete_t*)&robot_interaction_data.user_data;
    interaction_layer_delete->delete_type = type;
    interaction_layer_delete->layer = layer;
}

uint8_t delete_buf[17]{0};
/**
 * @brief 图层删除发送
 * 
 */
void UILayerDelete::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header至发送数组
    memcpy(delete_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(delete_buf, sizeof(frame_header));  //添加CRC8校验至发送数组

    //copy cmd_id至发送数组
    memcpy(delete_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data至发送数组
    memcpy(delete_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(delete_buf, length);  //添加CRC16校验至发送数组

    HAL_UART_Transmit_DMA(kRefereeUart, delete_buf, sizeof(delete_buf));
}

/**
 * @brief Construct a new UIOneFigure::UIOneFigure object
 * 
 * @param sender_id 发送者ID
 * @param receiver_id 接收者ID
 */
UIOneFigure::UIOneFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //帧头固定为0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0101;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief 一个图形发送配置
 * 
 * @param interaction_figure 图形配置结构体
 */
void UIOneFigure::Config(interaction_figure_t* interaction_figure) {
    memcpy((uint8_t*)&robot_interaction_data.user_data, interaction_figure,
           sizeof(interaction_figure_t));
}

uint8_t one_figure_buf[30]{0};
/**
 * @brief 一个图形发送
 * 
 */
void UIOneFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header至发送数组
    memcpy(one_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(one_figure_buf, sizeof(frame_header));  //添加CRC8校验至发送数组

    //copy cmd_id至发送数组
    memcpy(one_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data至发送数组
    memcpy(one_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(one_figure_buf, length);  //添加CRC16校验至发送数组

    HAL_UART_Transmit_DMA(kRefereeUart, one_figure_buf, sizeof(one_figure_buf));
}

/**
 * @brief Construct a new UITwoFigure::UITwoFigure object
 * 
 * @param sender_id 发送者ID
 * @param receiver_id 接收者ID
 */
UITwoFigure::UITwoFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //帧头固定为0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0102;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief 两个图形发送配置
 * 
 * @param interaction_figure 图形配置结构体
 */
void UITwoFigure::Config(interaction_figure_t* interaction_figure1,
                         interaction_figure_t* interaction_figure2) {
    memcpy((uint8_t*)&robot_interaction_data.user_data, interaction_figure1,
           sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t),
           interaction_figure2, sizeof(interaction_figure_t));
}

uint8_t two_figure_buf[45]{0};
/**
 * @brief 两个图形发送
 * 
 */
void UITwoFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header至发送数组
    memcpy(two_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(two_figure_buf, sizeof(frame_header));  //添加CRC8校验至发送数组

    //copy cmd_id至发送数组
    memcpy(two_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data至发送数组
    memcpy(two_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(two_figure_buf, length);  //添加CRC16校验至发送数组

    HAL_UART_Transmit_DMA(kRefereeUart, two_figure_buf, sizeof(two_figure_buf));
}

/**
 * @brief Construct a new UIFiveFigure::UIFiveFigure object
 * 
 * @param sender_id 发送者ID
 * @param receiver_id 接收者ID
 */
UIFiveFigure::UIFiveFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //帧头固定为0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0103;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief 五个图形发送配置
 * 
 * @param interaction_figure 图形配置结构体
 */
void UIFiveFigure::Config(interaction_figure_t* interaction_figure1,
                          interaction_figure_t* interaction_figure2,
                          interaction_figure_t* interaction_figure3,
                          interaction_figure_t* interaction_figure4,
                          interaction_figure_t* interaction_figure5) {
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 0,
           interaction_figure1, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 1,
           interaction_figure2, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 2,
           interaction_figure3, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 3,
           interaction_figure4, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 4,
           interaction_figure5, sizeof(interaction_figure_t));
}

uint8_t five_figure_buf[90]{0};
int len;
/**
 * @brief 五个图形发送
 * 
 */
void UIFiveFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    len = length;

    //copy header至发送数组
    memcpy(five_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(five_figure_buf, sizeof(frame_header));  //添加CRC8校验至发送数组

    //copy cmd_id至发送数组
    memcpy(five_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data至发送数组
    memcpy(five_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(five_figure_buf, length);  //添加CRC16校验至发送数组

    HAL_UART_Transmit_DMA(kRefereeUart, five_figure_buf, sizeof(five_figure_buf));
}

/**
 * @brief Construct a new UISevenFigure::UISevenFigure object
 * 
 * @param sender_id 发送者ID
 * @param receiver_id 接收者ID
 */
UISevenFigure::UISevenFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //帧头固定为0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0104;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief 七个图形发送配置
 * 
 * @param interaction_figure 图形配置结构体
 */
void UISevenFigure::Config(interaction_figure_t* interaction_figure1,
                           interaction_figure_t* interaction_figure2,
                           interaction_figure_t* interaction_figure3,
                           interaction_figure_t* interaction_figure4,
                           interaction_figure_t* interaction_figure5,
                           interaction_figure_t* interaction_figure6,
                           interaction_figure_t* interaction_figure7) {
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 0,
           interaction_figure1, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 1,
           interaction_figure2, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 2,
           interaction_figure3, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 3,
           interaction_figure4, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 4,
           interaction_figure5, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 5,
           interaction_figure6, sizeof(interaction_figure_t));
    memcpy((uint8_t*)&robot_interaction_data.user_data + sizeof(interaction_figure_t) * 6,
           interaction_figure7, sizeof(interaction_figure_t));
}

uint8_t seven_figure_buf[120]{0};
/**
 * @brief 七个图形发送
 * 
 */
void UISevenFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header至发送数组
    memcpy(seven_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(seven_figure_buf, sizeof(frame_header));  //添加CRC8校验至发送数组

    //copy cmd_id至发送数组
    memcpy(seven_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data至发送数组
    memcpy(seven_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(seven_figure_buf, length);  //添加CRC16校验至发送数组

    HAL_UART_Transmit_DMA(kRefereeUart, seven_figure_buf, sizeof(seven_figure_buf));
}

/**
 * @brief Construct a new UIcharacterFigure::UIcharacterFigure object
 * 
 * @param sender_id 发送者ID
 * @param receiver_id 接收者ID
 */
UIcharacterFigure::UIcharacterFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //帧头固定为0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0110;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief 字符发送配置
 * 
 * @param interaction_figure 图形配置结构体
 */
void UIcharacterFigure::config(interaction_figure_t* interaction_figure) {
    memcpy((uint8_t*)&robot_interaction_data.user_data, interaction_figure,
           sizeof(interaction_figure_t));
}

uint8_t character_buf[60]{0};
/**
 * @brief 字符发送
 * 
 */
void UIcharacterFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header至发送数组
    memcpy(character_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(character_buf, sizeof(frame_header));  //添加CRC8校验至发送数组

    //copy cmd_id至发送数组
    memcpy(character_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data至发送数组
    memcpy(character_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(character_buf, length);  //添加CRC16校验至发送数组

    HAL_UART_Transmit_DMA(kRefereeUart, character_buf, sizeof(character_buf));
}

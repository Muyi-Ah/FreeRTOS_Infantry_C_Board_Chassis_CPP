/**
 * @file ui.cpp
 * @author XMX
 * @brief UI�෽��
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ui.hpp"
#include <cstring>
#include "crc.hpp"

/**
 * @brief Construct a new UILayerDelete::UILayerDelete object
 * 
 * @param sender_id ������ID
 * @param receiver_id ������ID
 */
UILayerDelete::UILayerDelete(uint16_t sender_id, uint16_t receiver_id) {

    header.SOF = 0xA5;  //֡ͷ�̶�Ϊ0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0100;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief ͼ��ɾ������
 * 
 * @param str ����
 * @param type ɾ������
 * @param layer ����
 */
void UILayerDelete::Config(DeleteType type, uint8_t layer) {
    interaction_layer_delete_t* interaction_layer_delete =
        (interaction_layer_delete_t*)&robot_interaction_data.user_data;
    interaction_layer_delete->delete_type = type;
    interaction_layer_delete->layer = layer;
}

uint8_t delete_buf[17]{0};
/**
 * @brief ͼ��ɾ������
 * 
 */
void UILayerDelete::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header����������
    memcpy(delete_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(delete_buf, sizeof(frame_header));  //���CRC8У������������

    //copy cmd_id����������
    memcpy(delete_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data����������
    memcpy(delete_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(delete_buf, length);  //���CRC16У������������

    HAL_UART_Transmit_DMA(kRefereeUart, delete_buf, sizeof(delete_buf));
}

/**
 * @brief Construct a new UIOneFigure::UIOneFigure object
 * 
 * @param sender_id ������ID
 * @param receiver_id ������ID
 */
UIOneFigure::UIOneFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //֡ͷ�̶�Ϊ0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0101;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief һ��ͼ�η�������
 * 
 * @param interaction_figure ͼ�����ýṹ��
 */
void UIOneFigure::Config(interaction_figure_t* interaction_figure) {
    memcpy((uint8_t*)&robot_interaction_data.user_data, interaction_figure,
           sizeof(interaction_figure_t));
}

uint8_t one_figure_buf[30]{0};
/**
 * @brief һ��ͼ�η���
 * 
 */
void UIOneFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header����������
    memcpy(one_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(one_figure_buf, sizeof(frame_header));  //���CRC8У������������

    //copy cmd_id����������
    memcpy(one_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data����������
    memcpy(one_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(one_figure_buf, length);  //���CRC16У������������

    HAL_UART_Transmit_DMA(kRefereeUart, one_figure_buf, sizeof(one_figure_buf));
}

/**
 * @brief Construct a new UITwoFigure::UITwoFigure object
 * 
 * @param sender_id ������ID
 * @param receiver_id ������ID
 */
UITwoFigure::UITwoFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //֡ͷ�̶�Ϊ0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0102;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief ����ͼ�η�������
 * 
 * @param interaction_figure ͼ�����ýṹ��
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
 * @brief ����ͼ�η���
 * 
 */
void UITwoFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header����������
    memcpy(two_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(two_figure_buf, sizeof(frame_header));  //���CRC8У������������

    //copy cmd_id����������
    memcpy(two_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data����������
    memcpy(two_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(two_figure_buf, length);  //���CRC16У������������

    HAL_UART_Transmit_DMA(kRefereeUart, two_figure_buf, sizeof(two_figure_buf));
}

/**
 * @brief Construct a new UIFiveFigure::UIFiveFigure object
 * 
 * @param sender_id ������ID
 * @param receiver_id ������ID
 */
UIFiveFigure::UIFiveFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //֡ͷ�̶�Ϊ0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0103;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief ���ͼ�η�������
 * 
 * @param interaction_figure ͼ�����ýṹ��
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
 * @brief ���ͼ�η���
 * 
 */
void UIFiveFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    len = length;

    //copy header����������
    memcpy(five_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(five_figure_buf, sizeof(frame_header));  //���CRC8У������������

    //copy cmd_id����������
    memcpy(five_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data����������
    memcpy(five_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(five_figure_buf, length);  //���CRC16У������������

    HAL_UART_Transmit_DMA(kRefereeUart, five_figure_buf, sizeof(five_figure_buf));
}

/**
 * @brief Construct a new UISevenFigure::UISevenFigure object
 * 
 * @param sender_id ������ID
 * @param receiver_id ������ID
 */
UISevenFigure::UISevenFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //֡ͷ�̶�Ϊ0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0104;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief �߸�ͼ�η�������
 * 
 * @param interaction_figure ͼ�����ýṹ��
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
 * @brief �߸�ͼ�η���
 * 
 */
void UISevenFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header����������
    memcpy(seven_figure_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(seven_figure_buf, sizeof(frame_header));  //���CRC8У������������

    //copy cmd_id����������
    memcpy(seven_figure_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data����������
    memcpy(seven_figure_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(seven_figure_buf, length);  //���CRC16У������������

    HAL_UART_Transmit_DMA(kRefereeUart, seven_figure_buf, sizeof(seven_figure_buf));
}

/**
 * @brief Construct a new UIcharacterFigure::UIcharacterFigure object
 * 
 * @param sender_id ������ID
 * @param receiver_id ������ID
 */
UIcharacterFigure::UIcharacterFigure(uint16_t sender_id, uint16_t receiver_id) {
    header.SOF = 0xA5;  //֡ͷ�̶�Ϊ0xA5
    header.data_length = sizeof(robot_interaction_data);

    robot_interaction_data.data_cmd_id = 0x0110;
    robot_interaction_data.sender_id = sender_id;
    robot_interaction_data.receiver_id = receiver_id;
}

/**
 * @brief �ַ���������
 * 
 * @param interaction_figure ͼ�����ýṹ��
 */
void UIcharacterFigure::config(interaction_figure_t* interaction_figure) {
    memcpy((uint8_t*)&robot_interaction_data.user_data, interaction_figure,
           sizeof(interaction_figure_t));
}

uint8_t character_buf[60]{0};
/**
 * @brief �ַ�����
 * 
 */
void UIcharacterFigure::Send() {
    const auto length =
        sizeof(frame_header) + sizeof(cmd_id) + sizeof(robot_interaction_data) + sizeof(frame_tail);

    //copy header����������
    memcpy(character_buf, &header, sizeof(frame_header));

    header.seq++;

    Append_CRC8_Check_Sum(character_buf, sizeof(frame_header));  //���CRC8У������������

    //copy cmd_id����������
    memcpy(character_buf + sizeof(frame_header), &cmd_id, sizeof(cmd_id));
    //copy data����������
    memcpy(character_buf + sizeof(frame_header) + sizeof(cmd_id), &robot_interaction_data,
           sizeof(robot_interaction_data));

    Append_CRC16_Check_Sum(character_buf, length);  //���CRC16У������������

    HAL_UART_Transmit_DMA(kRefereeUart, character_buf, sizeof(character_buf));
}

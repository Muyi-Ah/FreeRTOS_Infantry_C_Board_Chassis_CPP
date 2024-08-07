/**
 * @file communication.cpp
 * @author XMX
 * @brief ���ͨ�ź������෽��
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "communication.hpp"
#include <cstdint>
#include "chassis.hpp"
#include "string.h"
#include "uart.hpp"
#include "variables.hpp"

/// @brief �Ӻ�У��
/// @param buf ͨ����������
/// @param lenght �����ܳ�
/// @return У��ֵ
static int32_t summation(const uint8_t* buf, uint16_t lenght) {
    int32_t result = 0;
    for (uint8_t index = 0; index < lenght - 4; index++) {
        result += buf[index];
    }
    return result;
}

/// @brief ��ӼӺ�У��
/// @param buf ͨ����������
/// @param length �����ܳ�
static void AppendAccumulationCheckSum(uint8_t* buf, uint16_t length) {
    int32_t result = 0;

    result = summation(buf, length);

    buf[length - 4] = result;
    buf[length - 3] = result >> 8;
    buf[length - 2] = result >> 16;
    buf[length - 1] = result >> 24;
}

/// @brief У��
/// @param buf ͨ����������
/// @param lenght �����ܳ�
/// @return true or false
static uint8_t VerifyAccumulationCheckSum(const uint8_t* buf, uint16_t lenght) {
    int32_t buffer_result;
    int32_t accumulation_result;

    buffer_result =
        buf[lenght - 4] | buf[lenght - 3] << 8 | buf[lenght - 2] << 16 | buf[lenght - 1] << 24;

    accumulation_result = summation(buf, lenght);

    if (buffer_result == accumulation_result) {
        return true;
    } else {
        return false;
    }
}

/// @brief ���ͨ�����ݽ��
/// @param buf ��������
void Communicator::RecvUpdate(const uint8_t* buf) {
    if (VerifyAccumulationCheckSum(buf, kCommRecvSize)) {
        memcpy(&dr16, buf, sizeof(dr16));
        memcpy(&theta, buf + sizeof(dr16), sizeof(float));
        memcpy(&vision_is_use, buf + sizeof(dr16) + sizeof(float), sizeof(bool));
        memcpy(&vision_aim_type, buf + sizeof(dr16) + sizeof(float) + sizeof(bool),
               sizeof(vision_aim_type));
        memcpy(&friction_is_enable,
               buf + sizeof(dr16) + sizeof(float) + sizeof(bool) + sizeof(vision_aim_type),
               sizeof(friction_is_enable));
        memcpy(&vision_is_aimed,
               buf + sizeof(dr16) + sizeof(float) + sizeof(bool) + sizeof(vision_aim_type) +
                   sizeof(friction_is_enable),
               sizeof(vision_is_aimed));
    }
}

uint8_t buf[sizeof(float) + 4]{0};
/// @brief ͨ�����ݷ���
void Communicator::Send() {
    memcpy(buf, &vw, sizeof(vw));
    AppendAccumulationCheckSum(buf, sizeof(buf));
    HAL_UART_Transmit_DMA(kCommUart, buf, sizeof(buf));
}

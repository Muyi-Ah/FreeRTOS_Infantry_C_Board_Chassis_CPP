/**
 * @file clamp.cpp
 * @author XMX
 * @brief �޷�����
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "clamp.hpp"
#include <cstdint>

/// @brief float�����޷�
/// @param value ��ʼֵ
/// @param min ��Сֵ
/// @param max ���ֵ
/// @return �޷����ֵ
float clamp(float value, float min, float max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

/// @brief �����޷�
/// @param value ��ʼֵ
/// @param min ��Сֵ
/// @param max ���ֵ
/// @return �޷����ֵ
int32_t clamp(int32_t value, int32_t min, int32_t max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

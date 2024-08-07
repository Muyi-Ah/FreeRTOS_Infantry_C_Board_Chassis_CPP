/**
 * @file clamp.cpp
 * @author XMX
 * @brief 限幅函数
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "clamp.hpp"
#include <cstdint>

/// @brief float类型限幅
/// @param value 初始值
/// @param min 最小值
/// @param max 最大值
/// @return 限幅后的值
float clamp(float value, float min, float max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

/// @brief 整形限幅
/// @param value 初始值
/// @param min 最小值
/// @param max 最大值
/// @return 限幅后的值
int32_t clamp(int32_t value, int32_t min, int32_t max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

/**
 * @file simple_math.cpp
 * @author XMX
 * @brief 简单数学函数
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "simple_math.hpp"

/// @brief 角度转弧度
/// @param degrees 角度
/// @return 弧度
float deg2rad(float degrees) {
    return degrees * (kPI / 180.0f);
}

/// @brief 弧度转角度
/// @param radians 弧度
/// @return 角度
float rad2deg(float radians) {
    return radians * (180.0f / kPI);
}

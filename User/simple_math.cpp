/**
 * @file simple_math.cpp
 * @author XMX
 * @brief ����ѧ����
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "simple_math.hpp"

/// @brief �Ƕ�ת����
/// @param degrees �Ƕ�
/// @return ����
float deg2rad(float degrees) {
    return degrees * (kPI / 180.0f);
}

/// @brief ����ת�Ƕ�
/// @param radians ����
/// @return �Ƕ�
float rad2deg(float radians) {
    return radians * (180.0f / kPI);
}

/**
 * @file tracking_differentiator.cpp
 * @author XMX
 * @brief ΢�ָ������෽��
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "tracking_differentiator.hpp"

/// @brief ΢�ָ���������
/// @param u ����ֵ
/// @return �˲�ֵ
float TD::Compute(float u) {
    u_ = u;
    x1_ += x2_ * h_;
    x2_ += (-2.0f * r_ * x2_ - r_ * r_ * (x1_ - u_)) * h_;
    return x1_;
}

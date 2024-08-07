/**
 * @file tracking_differentiator.cpp
 * @author XMX
 * @brief 微分跟踪器类方法
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "tracking_differentiator.hpp"

/// @brief 微分跟踪器计算
/// @param u 输入值
/// @return 滤波值
float TD::Compute(float u) {
    u_ = u;
    x1_ += x2_ * h_;
    x2_ += (-2.0f * r_ * x2_ - r_ * r_ * (x1_ - u_)) * h_;
    return x1_;
}

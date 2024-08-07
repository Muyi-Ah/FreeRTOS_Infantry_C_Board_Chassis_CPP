/**
 * @file pid.cpp
 * @author XMX
 * @brief PID类方法
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "pid.hpp"

/// @brief PID限幅
/// @param value 初始值
/// @param min 最小值
/// @param max 最大值
/// @return 限幅后的值
float PID::clamp(float value, float min, float max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

/// @brief PID计算
/// @param target 目标值
/// @param measure 实际值
/// @return PID输出值
float PID::Compute(float target, float measure) {
    error_ = target - measure;
    integral_ += error_;
    integral_ = clamp(integral_, -integral_limit_, integral_limit_);
    derivative_ = error_ - prev_error_;
    prev_error_ = error_;
    output_ = kp_ * error_ + ki_ * integral_ + kd_ * derivative_;
    output_ = clamp(output_, -output_limit_, output_limit_);
    return output_;
}

/// @brief PID计算（误差值输入）
/// @param error 误差值
/// @return PID输出值
float PID::Compute(float error) {
    error_ = error;
    integral_ += error_;
    integral_ = clamp(integral_, -integral_limit_, integral_limit_);
    derivative_ = error_ - prev_error_;
    prev_error_ = error_;
    output_ = kp_ * error + ki_ * integral_ + kd_ * derivative_;
    output_ = clamp(output_, -output_limit_, output_limit_);
    return output_;
}

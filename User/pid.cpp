/**
 * @file pid.cpp
 * @author XMX
 * @brief PID�෽��
 * @version 1.0
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "pid.hpp"

/// @brief PID�޷�
/// @param value ��ʼֵ
/// @param min ��Сֵ
/// @param max ���ֵ
/// @return �޷����ֵ
float PID::clamp(float value, float min, float max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

/// @brief PID����
/// @param target Ŀ��ֵ
/// @param measure ʵ��ֵ
/// @return PID���ֵ
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

/// @brief PID���㣨���ֵ���룩
/// @param error ���ֵ
/// @return PID���ֵ
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

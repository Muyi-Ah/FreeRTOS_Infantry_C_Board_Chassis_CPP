#pragma once

extern float target_rpm_201;
extern float target_rpm_202;
extern float target_rpm_203;
extern float target_rpm_204;
extern float max_rpm;
extern float vw;

#ifdef __cplusplus
extern "C" {
#endif

void ChassisTask(void* argument);

#ifdef __cplusplus
}
#endif
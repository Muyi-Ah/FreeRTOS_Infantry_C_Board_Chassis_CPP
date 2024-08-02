#pragma once
#include <cstdint>

enum AimType {
    kArmor,
    kRobotHub,
};

class Communicator {
   public:
    float theta = 0;
    bool vision_is_use = false;
    AimType vision_aim_type;
    bool friction_is_enable;
    bool vision_is_aimed;

	void RecvUpdate(const uint8_t* buf);
    void Send();
	bool is_reply_ = false;
};

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

	void RecvUpdate(const uint8_t* buf);
    void Send();
	bool is_reply_ = false;

   private:
};

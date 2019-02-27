// Robot.h

#ifndef _ROBOT_h
#define _ROBOT_h

#include "Motor.h"
#include "MotorBoard.h"

class RobotClass
{
 private:
    static void InitializeMotorPinout();
	static void InitializeUltrasonicPinout();
	void CreateMotorsAndControl();

	MotorBoardClass * motor_board_ = nullptr;
	MotorClass * motors_[4] = {};

 public:
	void init();
	void Drive(int direction, int distance) const;
};

extern RobotClass Robot;

#endif


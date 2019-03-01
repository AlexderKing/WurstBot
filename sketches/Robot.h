// Robot.h

#ifndef _ROBOT_h
#define _ROBOT_h

#include "Motor.h"
#include "MotorBoard.h"

#include "HCSR04.h"
#include "MazeMap.h"

class RobotClass
{
 private:
    static void InitializeMotorPinout();
	static void InitializeUltrasonicPinout();
	void CreateMotorsAndControl();
	void CreateUltrasonicAndControl();

	MotorBoardClass * motor_board_ = nullptr;
	MotorClass * motors_[4] = {};
    
	HCSR04Class * us_[4] = {};
    
    MazeMap* map = nullptr;

 public:
	void init();
	void Drive(int direction, int distance) const;
	bool* ScanWalls();
    void Maze();
};

extern RobotClass Robot;

#endif


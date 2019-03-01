#include "Robot.h"

#include "Pinout.h"
#include "Tools.h"

void RobotClass::CreateMotorsAndControl() {
	motor_board_ = new MotorBoardClass();

	for (auto i = 0; i < 4; i++) {
		motors_[i] = new MotorClass();
	}

    motors_[0]->init(kmotor_1_enable, kmotor_1_direction);
    motors_[1]->init(kmotor_2_enable, kmotor_2_direction);
    motors_[2]->init(kmotor_3_enable, kmotor_3_direction);
    motors_[3]->init(kmotor_4_enable, kmotor_4_direction);

	motor_board_->init(kpull_pin, motors_);
}

void RobotClass::init()
{
	InitializeMotorPinout();
    InitializeUltrasonicPinout();
    CreateMotorsAndControl();
    CreateUltrasonicAndControl();
    
    this->map = new MazeMap();
    this->map->InitializeRobotTile();
}

void RobotClass::CreateUltrasonicAndControl()
{
	for (auto i = 0; i < 4; i++) {
		us_[i] = new HCSR04Class();
	}
    
	us_[0]->init(kultrasonic_1_trig, kultrasonic_1_echo);
	us_[1]->init(kultrasonic_2_trig, kultrasonic_2_echo);
	us_[2]->init(kultrasonic_3_trig, kultrasonic_3_echo);
	us_[3]->init(kultrasonic_4_trig, kultrasonic_4_echo);
}

void RobotClass::Drive(const int direction, const int distance) const {
	motor_board_->DriveInDirection(direction, kradius, distance, kmotor_speed);
}

bool* RobotClass::ScanWalls() {
	bool walls[4];
	for (auto i = 0; i < 4; i++) {
		walls[i] = us_[i]->IsWall();
		if (walls[i])
		{
			Serial.print("WALL | ");
		}
		else
		{
			Serial.print("NOWALL | ");
		}
	}

	return walls;
}

void RobotClass::InitializeMotorPinout() {

    Serial.print("Initialize motor pins ...");

    pinMode(kmotor_1_direction, OUTPUT);
    pinMode(kmotor_1_enable, OUTPUT);
    pinMode(kmotor_2_direction, OUTPUT);
    pinMode(kmotor_2_enable, OUTPUT);
    pinMode(kmotor_3_direction, OUTPUT);
    pinMode(kmotor_3_enable, OUTPUT);
    pinMode(kmotor_4_direction, OUTPUT);
    pinMode(kmotor_4_enable, OUTPUT);

    pinMode(kpull_pin, OUTPUT);

    Serial.println("finished");
}

void RobotClass::InitializeUltrasonicPinout() {
	Serial.println("Initialize ultrasonic pins ...");

	pinMode(kultrasonic_1_echo, INPUT);
	pinMode(kultrasonic_1_trig, OUTPUT);
	pinMode(kultrasonic_2_echo, INPUT);
	pinMode(kultrasonic_2_trig, OUTPUT);
	pinMode(kultrasonic_3_echo, INPUT);
	pinMode(kultrasonic_3_trig, OUTPUT);
	pinMode(kultrasonic_4_echo, INPUT);
	pinMode(kultrasonic_4_trig, OUTPUT);

	Serial.println("finished");
}

void RobotClass::Maze()
{
    while (true)
    {
        bool* walls = ScanWalls();
        int state = map->MoveRobotToNextPosition(walls);
        if (state == finished) break;
        if (state == pass) continue;
        if (state > 3) state -= 128;
        
        Drive(state, 30);
        delay(1000);
        motor_board_->DisableAllMotors();
        delay(3000);
    }
}

RobotClass Robot;

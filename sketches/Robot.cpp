#include "Robot.h"

#include "Pinout.h"

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
}

void RobotClass::Drive(const int direction, const int distance) const {
	motor_board_->DriveInDirection(direction, kradius, distance, kmotor_speed);
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
	pinMode(kultrasonic_1_echo, INPUT);
	pinMode(kultrasonic_1_trig, OUTPUT);
}

RobotClass Robot;

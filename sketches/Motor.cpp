#include "Motor.h"

void MotorClass::init(const int enable_pin, const int direction_pin)
{
	this->enable_pin_ = enable_pin;
	this->direction_pin_ = direction_pin;
}

void MotorClass::ChangeStatus(const int new_status)
{
	this->status_ = new_status;
	ApplyChanges();
}

void MotorClass::ChangeDirection(const int new_direction)
{
	this->direction_ = new_direction;
	ApplyChanges();
}

void MotorClass::ApplyChanges() const
{
	digitalWrite(enable_pin_, status_);
	digitalWrite(direction_pin_, direction_);
	Serial.println("Applied changes");
}


MotorClass Motor;


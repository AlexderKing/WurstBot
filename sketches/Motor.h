// Motor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Enums.h"

#include <stdint.h>

class MotorClass final
{
private:
	uint8_t enable_pin_ = -1;
	uint8_t direction_pin_ = -1;

	uint8_t status_ = Status::Disabled;
	uint8_t direction_ = Direction::Right;

	void ApplyChanges() const;

 public:
	void init(int enable_pin, int direction_pin);
	
	void ChangeStatus(int new_status);
	void ChangeDirection(int new_direction);
};

extern MotorClass Motor;

#endif

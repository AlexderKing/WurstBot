#include "HCSR04.h"

void HCSR04Class::init(uint8_t trigger_pin, uint8_t echo_pin)
{
	this->trigger_pin_ = trigger_pin;
	this->echo_pin_ = echo_pin;
}

int HCSR04Class::ReadDistanceInCm() {
    // Clear the trigger Pin
	digitalWrite(trigger_pin_, LOW);
	delayMicroseconds(2);

    // Send signal
	digitalWrite(trigger_pin_, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigger_pin_, LOW);

    // Read the incoming signal and transform it to cm
	const long duration = pulseIn(echo_pin_, HIGH);
//	Serial.print("Duration: ");
//	Serial.println(duration);
	return duration * 0.034f / 2;
}

bool HCSR04Class::IsWall() {
	if (ReadDistanceInCm() < 12)
	{
		return true;
	}

	return false;
}

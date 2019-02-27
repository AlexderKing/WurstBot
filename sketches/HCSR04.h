#pragma once

#ifndef HCSR04_H_
#define HCSR04_H_

#if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
#else
    #include "WProgram.h"
#endif

#include <stdint.h>

// ReSharper disable once CppInconsistentNaming
class HCSR04Class final
{
public:
	void init(uint8_t trigger_pin, uint8_t echo_pin);
	int ReadDistanceInCm();

private:
	uint8_t trigger_pin_;
	uint8_t echo_pin_;
};

extern HCSR04Class HCSR04;
#endif // HCSR04_H_

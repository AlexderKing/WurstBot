// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       WurstBot.ino
    Created:	25/02/2019 22:14:10
    Author:     DESKTOP-BSHP86P\The stolen Bratwurst
*/
#include "Robot.h"

#include "Pinout.h"
#include "HCSR04.h"


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//


// The setup() function runs once each time the micro-controller starts

HCSR04Class* us;

void setup()
{
    Serial.begin(9600);
	us = new HCSR04Class();
	us->init(kultrasonic_1_trig, kultrasonic_1_echo);
	auto* robot = new RobotClass();
	robot->init();
	
//	pinMode(kmotor_1_direction, OUTPUT);
//	pinMode(kmotor_1_enable, OUTPUT);
//	pinMode(kpull_pin, OUTPUT);
//	
//	digitalWrite(kmotor_1_enable, LOW);
//	
//	for (int i = 0; i < 400; i++)
//	{
//		digitalWrite(kpull_pin, HIGH);
//		delay(600);
//		
//	}
//	
	//Serial.println("Should drive now");

	/*robot->Drive(0, 10);
	delay(3000);
	robot->Drive(1, 10);
	delay(3000);
	robot->Drive(2, 10);
	delay(3000);
	robot->Drive(3, 10);*/
}

// Add the main program code into the continuous loop() function
void loop()
{
	Serial.print("Distance: ");
	auto d = us->ReadDistanceInCm();
	Serial.print(d);
	Serial.println("cm");

	delay(500);

}

// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       WurstBot.ino
    Created:	25/02/2019 22:14:10
    Author:     DESKTOP-BSHP86P\The stolen Bratwurst
*/
#include <variant.h>
#include "Robot.h"

#include "pinout.h"


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//


// The setup() function runs once each time the micro-controller starts


void setup()
{
    Serial.begin(9600);
	
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
	Serial.println("Should drive now");
	robot->Drive(0, 30);
	robot->Drive(1, 30);
	robot->Drive(2, 30);
	robot->Drive(3, 30);
}

// Add the main program code into the continuous loop() function
void loop()
{


}

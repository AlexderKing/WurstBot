#include <Wire.h>
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

RobotClass* robot;

void setup()
{
    Serial.begin(9600);
	robot = new RobotClass();
	robot->init();
	
	Serial.println("Should drive now");

	robot->Drive(0, 30);
	/*delay(3000);
	robot->Drive(1, 10);*/
	delay(3000);
	robot->Drive(2, 30);
	/*delay(3000);
	robot->Drive(3, 10);*/
}

// Add the main program code into the continuous loop() function
void loop()
{ 
	/*robot->ScanWalls();
	Serial.println("");

	delay(1000);
*/
}

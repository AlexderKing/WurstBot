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
#include "GYSensor.h"


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//


// The setup() function runs once each time the micro-controller starts

RobotClass* robot;
//GYSensor* gys;

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    
    
    //gys = new GYSensor();
	robot = new RobotClass();
    
    //gys->init(0x68);
	robot->init();
	
	Serial.println("Should drive now");

    robot->Maze();
    
    //robot->Drive(1, 30);
    //robot->Drive(2, 30);
}

// Add the main program code into the continuous loop() function
void loop()
{ 
//    gys->read();
//    uint16_t temp = gys->GetTemperature();
//    Serial.print("Temp: ");
//    Serial.println(temp);
	/*robot->ScanWalls();
	Serial.println("");

	delay(1000);
*/
}

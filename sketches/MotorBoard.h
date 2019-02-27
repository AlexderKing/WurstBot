// MotorBoard.h

#ifndef MOTORBOARD_H_
#define MOTORBOARD_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "CONSTS.h"
#include "Enums.h"
#include "Motor.h"

#include <stdint.h>

class MotorBoardClass final {
private:
    uint8_t pullPin = -1;
    MotorClass** motors = nullptr;

	void ChangeStatus(int status1,
		int status2,
		int status3,
		int status4) const;

    void EnableAllMotors() const {
        ChangeStatus(Status::Enabled, Status::Enabled, Status::Enabled,
                     Status::Enabled);
    }

    void DisableAllMotors() const {
        ChangeStatus(Status::Disabled, Status::Disabled, Status::Disabled,
                     Status::Disabled);
    }

    void ChangeDirection(int dir1, int dir2, int dir3, int dir4) const;
    void ChangeDirection(int dir[4]) const;

    void Pull(int speed = kmotor_speed) const;
    void PullSteps(int steps, int speed = kmotor_speed) const;

public:
    ~MotorBoardClass();

    void init(uint8_t pull_pin, MotorClass* motors[4]);

    void DriveInDirection(int moving_direction, int radius, int distance_in_cm,
                          int speed);

};

//extern MotorBoardClass MotorBoard;

#endif

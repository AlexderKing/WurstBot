#include "MotorBoard.h"
#include "Consts.h"

#include <stdint.h>
#include <math.h>

void MotorBoardClass::init(const uint8_t pull_pin, MotorClass* motors[4]) {
    this->pullPin = pull_pin;
    this->motors = new MotorClass*[4];

    for (auto i = 0; i < 4; i++) {
        this->motors[i] = motors[i];
    }

    DisableAllMotors();
}

MotorBoardClass::~MotorBoardClass() {
    delete[] motors;
    motors = nullptr;
}

void MotorBoardClass::ChangeStatus(const int status1, const int status2,
                                   const int status3,
                                   const int status4) const {
    motors[0]->ChangeStatus(status1);
    motors[1]->ChangeStatus(status2);
    motors[2]->ChangeStatus(status3);
    motors[3]->ChangeStatus(status4);
}

void MotorBoardClass::ChangeDirection(const int dir1, const int dir2,
                                      const int dir3,
                                      const int dir4) const {
    motors[0]->ChangeDirection(dir1);
    motors[1]->ChangeDirection(dir2);
    motors[2]->ChangeDirection(dir3);
    motors[3]->ChangeDirection(dir4);
}

void MotorBoardClass::ChangeDirection(int dir[4]) const {
    for (auto i = 0; i < 4; i++)
        motors[i]->ChangeDirection(dir[i]);
}

void MotorBoardClass::Pull(const int speed) const {
    digitalWrite(pullPin, HIGH);
    delayMicroseconds(speed);
    digitalWrite(pullPin, LOW);
    delayMicroseconds(speed);
}

void MotorBoardClass::PullSteps(const int steps, const int speed) const {
    for (auto i = 0; i < steps; i++) {
        Pull(speed);
    }
}


void MotorBoardClass::DriveInDirection(const int moving_direction,
                                       const int radius,
                                       const int distance_in_cm,
                                       int speed) {
    //   /   |   \ p
    //  /    |    \    to be continued
    // /     |    /\ <== 90°
    // \     |    \/
    //  \    |b   /
    //   \   |   /  p
    //   p\  |  /
    //     \ | /
    //      \|/ <== 90°
    // 2rπ = p
    // ==> b = sqrt(2p²)

    Serial.println("Enabling motors");
    const int steps = sqrt(2 * powf(radius * 2 * PI, 2)) * distance_in_cm / 2;
    Serial.print("Steps: ");
    Serial.println(steps);

    int directions[4][4] = {
        {Direction::Left, Direction::Right, Direction::Right, Direction::Left},
        {Direction::Right, Direction::Right, Direction::Left, Direction::Left},
        {Direction::Right, Direction::Left, Direction::Left, Direction::Right},
        {Direction::Left, Direction::Left, Direction::Right, Direction::Right}
    };

    EnableAllMotors();
    ChangeDirection(directions[moving_direction]);
    
    PullSteps(steps, kmotor_speed);
	DisableAllMotors();
    Serial.println("Disabling motors");
}


MotorBoardClass MotorBoard;

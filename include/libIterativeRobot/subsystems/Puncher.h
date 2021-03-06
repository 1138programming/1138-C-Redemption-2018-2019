#ifndef _SUBSYSTEMS_PUNCHER_H_
#define _SUBSYSTEMS_PUNCHER_H_

#include "./Subsystem.h"
#include "main.h"

#include "abstractBaseClasses/Motor.h"

class Puncher : public libIterativeRobot::Subsystem {
  private:
    // Arm motors
    Motor* puncherMotor;

    //PIDController* armController;

  public:
    void initDefaultCommand();
    void move(int speed);
    Puncher();
};

#endif // _SUBSYSTEMS_PUNCHER_H_

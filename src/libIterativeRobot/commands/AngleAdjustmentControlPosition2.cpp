#include "libIterativeRobot/commands/AngleAdjustmentControlPosition2.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

AngleAdjustmentControlPosition2::AngleAdjustmentControlPosition2(unsigned int duration, int speed) {
  this->duration = duration;
  this->speed = speed;

  requires(Robot::angleAdjustment);
  this->priority = 2;

}

bool AngleAdjustmentControlPosition2::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void AngleAdjustmentControlPosition2::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("AngleAdjustment control initialized\n");
  startTime = pros::millis();
}

void AngleAdjustmentControlPosition2::execute() {
  //printf("AngleAdjustment control running\n");
  Robot::angleAdjustment->move(-KMotorPosition);
}

bool AngleAdjustmentControlPosition2::isFinished() {
  return pros::millis() > (startTime + duration);
}

void AngleAdjustmentControlPosition2::end() {
  // Code that runs when isFinished() returns true.
  //Robot::angleAdjustment->lock();
  Robot::angleAdjustment->move(0);
}

void AngleAdjustmentControlPosition2::interrupted() {
  // Code that runs when this command is interrPosition2ted by another one
  // with a higher priority.
  Robot::angleAdjustment->move(0);
}
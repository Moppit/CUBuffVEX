
#include "vex.h"

using namespace vex;

// Drivetrain motors
motor frontLeft(PORT15, gearSetting::ratio18_1, true);
motor midLeft(PORT13, gearSetting::ratio18_1, false);
motor backLeft(PORT11, gearSetting::ratio18_1, true);
motor frontRight(PORT16, gearSetting::ratio18_1, false);
motor midRight(PORT14, gearSetting::ratio18_1, true);
motor backRight(PORT12, gearSetting::ratio18_1, false);
// Lift Motors
motor liftLeftUpper(PORT18, gearSetting::ratio18_1, true);
motor liftRightUpper(PORT17, gearSetting::ratio18_1, false);
motor liftLeftLower(PORT1, gearSetting::ratio18_1, true);
motor liftRightLower(PORT19, gearSetting::ratio18_1, false);
// Grabber Motors
motor grabberLeft(PORT2, gearSetting::ratio18_1, true);
motor grabberRight(PORT20, gearSetting::ratio18_1, false);

controller Controller;

motor_group lift(liftLeftUpper, liftRightUpper, liftLeftLower, liftRightLower);
motor_group leftDriveMotors(frontLeft, midLeft, backLeft);
motor_group rightDriveMotors(frontRight, midRight, backRight);
motor_group allDriveMotors(frontLeft, midLeft, backLeft, frontRight, midRight, backRight);
motor_group grabberMotors(grabberLeft, grabberRight);

// For autonomous
motor_group auton_motors(grabberLeft, grabberRight, frontLeft, midLeft, backLeft, frontRight, midRight, backRight);

// A global instance of competition
competition Competition;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  // Drive forward toward the goal
  allDriveMotors.rotateFor(1, rotationUnits::rev, false);

  //let go of cube
  grabberMotors.setVelocity(100, velocityUnits::rpm);
  grabberMotors.rotateFor(10, rotationUnits::rev, false);

  // auton_motors.rotateFor(-3, rotationUnits::rev, false);

  //drive backwards
  allDriveMotors.rotateFor(-1, rotationUnits::rev, false);

}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // Tank Drive
    leftDriveMotors.spin(directionType::fwd, Controller.Axis3.value()/3, velocityUnits::rpm);
    rightDriveMotors.spin(directionType::fwd, Controller.Axis2.value()/3, velocityUnits::rpm);

    // Lift Arms
    if(Controller.ButtonR1.pressing())
    {
      lift.spin(directionType::fwd, 200, velocityUnits::rpm);
    }
    else if(Controller.ButtonR2.pressing())
    {
      lift.spin(directionType::rev, 200, velocityUnits::rpm);
    }
    else if(Controller.ButtonA.pressing())
    {
      lift.spin(directionType::fwd, 0, velocityUnits::rpm);
    }

    // Grabber
    if(Controller.ButtonL2.pressing())
    {
      grabberMotors.spin(directionType::fwd, 200, velocityUnits::rpm);
    }
    else if(Controller.ButtonL1.pressing())
    {
      grabberMotors.spin(directionType::rev, 200, velocityUnits::rpm);
    }
    else if(Controller.ButtonY.pressing())
    {
      grabberMotors.spin(directionType::fwd, 0, velocityUnits::rpm);
    }
 
    task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Testing auton -- take out later!
  // allDriveMotors.rotateFor(1, rotationUnits::rev, false);
  // grabberMotors.setVelocity(100, velocityUnits::rpm);
  // grabberMotors.rotateFor(10, rotationUnits::rev, false);
  // allDriveMotors.rotateFor(-1, rotationUnits::rev, false);
  ////////////

  // //Set up callbacks for autonomous and driver control periods.
  Competition.autonomous( autonomous );
  Competition.drivercontrol( usercontrol );
  
  //Run the pre-autonomous function. 
  pre_auton();
  
}

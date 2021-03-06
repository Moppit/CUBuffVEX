/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       michelletran                                              */
/*    Created:      Thu Oct 10 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
vex::controller Controller;
motor frontLeft(PORT11, gearSetting::ratio18_1, true);
motor midLeft(PORT12, gearSetting::ratio18_1, false);
motor backLeft(PORT13, gearSetting::ratio18_1, true);
motor frontRight(PORT20, gearSetting::ratio18_1, false);
motor midRight(PORT19, gearSetting::ratio18_1, true);
motor backRight(PORT18, gearSetting::ratio18_1, false);

// Storage lift
motor liftRight(PORT15, gearSetting::ratio18_1, true);
motor liftLeft(PORT16, gearSetting::ratio18_1, false);

// Intake
motor intakeRight(PORT10, gearSetting::ratio18_1, true);
motor intakeLeft(PORT1, gearSetting::ratio18_1, false);

motor_group leftDriveMotors(frontLeft, midLeft, backLeft);
motor_group rightDriveMotors(frontRight, midRight, backRight);
motor_group allDriveMotors(frontRight, midRight, backRight,frontLeft, midLeft, backLeft);
motor_group lift(liftRight, liftLeft);
motor_group intake(intakeLeft, intakeRight);


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

  //drive forward
  allDriveMotors.setVelocity(5, velocityUnits::rpm);
  allDriveMotors.rotateFor(0.5, rotationUnits::rev, false);
  allDriveMotors.setVelocity(20, velocityUnits::rpm);
  allDriveMotors.rotateFor(-0.75, rotationUnits::rev, false);

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

    // Set the left wheels to Axis 3 value
    leftDriveMotors.spin(directionType::fwd, Controller.Axis3.value()/3, vex::velocityUnits::rpm);

    // Set the right wheels to Axis 2 value
    rightDriveMotors.spin(directionType::fwd, Controller.Axis2.value()/3, vex::velocityUnits::rpm);
 
    // Lift
    int lift_power = 200;
    if(Controller.ButtonR1.pressing())
    {
      lift.spin(directionType::fwd, lift_power, vex::velocityUnits::rpm);
    }
    else if(Controller.ButtonR2.pressing())
    {
      lift.spin(directionType::rev, lift_power, vex::velocityUnits::rpm);
    }
    else if(Controller.ButtonA.pressing())
    {
      lift.stop();
    }

     // Intake
    int intake_power = 100;
    if(Controller.ButtonL1.pressing())
    {
      intake.spin(directionType::fwd, intake_power, vex::velocityUnits::rpm);
    }
    else if(Controller.ButtonL2.pressing())
    {
      intake.spin(directionType::rev, intake_power, vex::velocityUnits::rpm);
    }
    else if(Controller.ButtonY.pressing())
    {
      intake.stop();
    }
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}
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

// Drivetrain motors
vex::motor frontLeft(vex::PORT15, vex::gearSetting::ratio18_1, false);
vex::motor midLeft(vex::PORT13, vex::gearSetting::ratio18_1, true);
vex::motor backLeft(vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor frontRight(vex::PORT16, vex::gearSetting::ratio18_1, true);
vex::motor midRight(vex::PORT14, vex::gearSetting::ratio18_1, false);
vex::motor backRight(vex::PORT12, vex::gearSetting::ratio18_1, true);
// Lift Motors
vex::motor liftLeft(vex::PORT18, vex::gearSetting::ratio18_1, true);
vex::motor liftRight(vex::PORT17, vex::gearSetting::ratio18_1, false);

vex::controller Controller;

vex::motor_group lift(liftLeft, liftRight);
vex::motor_group leftDriveMotors(frontLeft, midLeft, backLeft);
vex::motor_group rightDriveMotors(frontRight, midRight, backRight);

// A global instance of vex::competition
vex::competition Competition;

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

    leftDriveMotors.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::rpm);
    rightDriveMotors.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::rpm);
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

int main() {
    // COMMENT OUT DURING COMPETITION -- for programming purposes only!
    usercontrol();

    // ---------- UNCOMMENT THE BELOW AT THE START OF THE COMPETITION ----------
    // //Set up callbacks for autonomous and driver control periods.
    // Competition.autonomous( autonomous );
    // Competition.drivercontrol( usercontrol );
    
    // //Run the pre-autonomous function. 
    // pre_auton();
       
    // //Prevent main from exiting with an infinite loop.                        
    // while(1) {
    //   vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    // }  

    // ------------------- Experimentation Code -- DON'T UNCOMMENT -----------------
    // while(true) {

    //     //lift.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::rpm);

    //     leftDriveMotors.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::rpm);

    //     //liftRight.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::rpm, false);
    //     //liftLeft.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::rpm);
      
    // }

    
    


    // END CONNECTING CONTROLLER TO ROBOT



    // ----------------------------------------------------
    
    // frontLeft.rotateFor(time, vex::timeUnits::sec);
    // midLeft.rotateFor(time, vex::timeUnits::sec);
    // backLeft.rotateFor(time, vex::timeUnits::sec);
    // frontRight.rotateFor(time, vex::timeUnits::sec);
    // midRight.rotateFor(time, vex::timeUnits::sec);
    // backRight.rotateFor(time, vex::timeUnits::sec);

    // frontLeft.spin(directionType::fwd); //frontLeft fwd goes backwards
    // frontRight.spin(directionType::fwd); //frontRight fwd goes backwards


    // THESE RUN SIMULTANEOUSLY
    // frontLeft.rotateFor(360, vex::rotationUnits::deg, false);
    // frontRight.rotateFor(360, vex::rotationUnits::deg);

    // liftRight.rotateFor(time, vex::timeUnits::sec);
    // liftLeft.rotateFor(time, vex::timeUnits::sec);

    // liftRight.rotateFor(90, vex::rotationUnits::deg, false);
    // liftLeft.rotateFor(90, vex::rotationUnits::deg);


    /* THESE RUN SIMULTANEOUSLY
    liftRight.rotateTo(30, vex::rotationUnits::deg, false);
    liftLeft.rotateTo(30, vex::rotationUnits::deg);

    task::sleep(3000);

    liftRight.rotateTo(-30, vex::rotationUnits::deg, false);
    liftLeft.rotateTo(-30, vex::rotationUnits::deg);
    // END SIMULTANEOUSLY  */

    // int count = 0;
   
    // while(1) {
    //     Brain.Screen.printAt( 10, 50, "Hello V5 %d", count++ );
    //     // Allow other tasks to run
    //     this_thread::sleep_for(10);
    // }
}

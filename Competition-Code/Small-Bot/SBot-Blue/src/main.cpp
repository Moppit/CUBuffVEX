
// ---- START VEXCODE CONFIGURED DEVICES ----
// #include "vex.h"
// 
// // ---- START VEXCODE CONFIGURED DEVICES ----
// // Robot Configuration:
// // [Name]               [Type]        [Port(s)]
// // ---- END VEXCODE CONFIGURED DEVICES ----
// 
// using namespace vex;
// 
// ---- END VEXCODE CONFIGURED DEVICES ----

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
motor liftLeft(PORT18, gearSetting::ratio18_1, true);
motor liftRight(PORT17, gearSetting::ratio18_1, false);

controller Controller;

motor_group lift(liftLeft, liftRight);
motor_group leftDriveMotors(frontLeft, midLeft, backLeft);
motor_group rightDriveMotors(frontRight, midRight, backRight);

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
    if(Controller.ButtonA.pressing())
    {
      lift.spin(directionType::fwd, 200, velocityUnits::rpm);
    }
 
    task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // //Set up callbacks for autonomous and driver control periods.
  Competition.autonomous( autonomous );
  Competition.drivercontrol( usercontrol );
  
  //Run the pre-autonomous function. 
  pre_auton();
  
}

// /*----------------------------------------------------------------------------*/
// /*                                                                            */
// /*    Module:       main.cpp                                                  */
// /*    Author:       michelletran                                              */
// /*    Created:      Thu Oct 10 2019                                           */
// /*    Description:  V5 project                                                */
// /*                                                                            */
// /*----------------------------------------------------------------------------*/
// #include "vex.h"
// 
// // ---- START VEXCODE CONFIGURED DEVICES ----
// // Robot Configuration:
// // [Name]               [Type]        [Port(s)]
// // ---- END VEXCODE CONFIGURED DEVICES ----
// 
// using namespace vex;
// 
// // A global instance of brain used for printing to the V5 brain screen
// brain       Brain;
// 
// // Drivetrain motors
// motor frontLeft(PORT15, gearSetting::ratio18_1, false);
// motor midLeft(PORT13, gearSetting::ratio18_1, true);
// motor backLeft(PORT11, gearSetting::ratio18_1, false);
// motor frontRight(PORT16, gearSetting::ratio18_1, true);
// motor midRight(PORT14, gearSetting::ratio18_1, false);
// motor backRight(PORT12, gearSetting::ratio18_1, true);
// // Lift Motors
// motor liftLeft(PORT18, gearSetting::ratio18_1, true);
// motor liftRight(PORT17, gearSetting::ratio18_1, false);
// 
// controller Controller;
// 
// motor_group lift(liftLeft, liftRight);
// motor_group leftDriveMotors(frontLeft, midLeft, backLeft);
// motor_group rightDriveMotors(frontRight, midRight, backRight);
// 
// // A global instance of competition
// competition Competition;
// 
// /*---------------------------------------------------------------------------*/
// /*                          Pre-Autonomous Functions                         */
// /*                                                                           */
// /*  You may want to perform some actions before the competition starts.      */
// /*  Do them in the following function.  You must return from this function   */
// /*  or the autonomous and usercontrol tasks will not be started.  This       */
// /*  function is only called once after the cortex has been powered on and    */ 
// /*  not every time that the robot is disabled.                               */
// /*---------------------------------------------------------------------------*/
// 
// void pre_auton( void ) {
//   // All activities that occur before the competition starts
//   // Example: clearing encoders, setting servo positions, ...
//   
// }
// 
// /*---------------------------------------------------------------------------*/
// /*                                                                           */
// /*                              Autonomous Task                              */
// /*                                                                           */
// /*  This task is used to control your robot during the autonomous phase of   */
// /*  a VEX Competition.                                                       */
// /*                                                                           */
// /*  You must modify the code to add your own robot specific commands here.   */
// /*---------------------------------------------------------------------------*/
// 
// void autonomous( void ) {
//   // ..........................................................................
//   // Insert autonomous user code here.
//   // ..........................................................................
// 
// }
// 
// /*---------------------------------------------------------------------------*/
// /*                                                                           */
// /*                              User Control Task                            */
// /*                                                                           */
// /*  This task is used to control your robot during the user control phase of */
// /*  a VEX Competition.                                                       */
// /*                                                                           */
// /*  You must modify the code to add your own robot specific commands here.   */
// /*---------------------------------------------------------------------------*/
// 
// void usercontrol( void ) {
//   // User control code here, inside the loop
//   while (1) {
//     // This is the main execution loop for the user control program.
//     // Each time through the loop your program should update motor + servo 
//     // values based on feedback from the joysticks.
// 
//     leftDriveMotors.spin(directionType::fwd, Controller.Axis3.value(), velocityUnits::rpm);
//     rightDriveMotors.spin(directionType::fwd, Controller.Axis2.value(), velocityUnits::rpm);
//  
//     task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
//   }
// }
// 
// int main() {
//     // COMMENT OUT DURING COMPETITION -- for programming purposes only!
//     usercontrol();
// 
//     // ---------- UNCOMMENT THE BELOW AT THE START OF THE COMPETITION ----------
//     // //Set up callbacks for autonomous and driver control periods.
//     // Competition.autonomous( autonomous );
//     // Competition.drivercontrol( usercontrol );
//     
//     // //Run the pre-autonomous function. 
//     // pre_auton();
//        
//     // //Prevent main from exiting with an infinite loop.                        
//     // while(1) {
//     //   task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
//     // }  
// 
//     // ------------------- Experimentation Code -- DON'T UNCOMMENT -----------------
//     // while(true) {
// 
//     //     //lift.spin(directionType::fwd, Controller.Axis3.value(), velocityUnits::rpm);
// 
//     //     leftDriveMotors.spin(directionType::fwd, Controller.Axis3.value(), velocityUnits::rpm);
// 
//     //     //liftRight.spin(directionType::fwd, Controller.Axis3.value(), velocityUnits::rpm, false);
//     //     //liftLeft.spin(directionType::fwd, Controller.Axis3.value(), velocityUnits::rpm);
//       
//     // }
// 
//     
//     
// 
// 
//     // END CONNECTING CONTROLLER TO ROBOT
// 
// 
// 
//     // ----------------------------------------------------
//     
//     // frontLeft.rotateFor(time, timeUnits::sec);
//     // midLeft.rotateFor(time, timeUnits::sec);
//     // backLeft.rotateFor(time, timeUnits::sec);
//     // frontRight.rotateFor(time, timeUnits::sec);
//     // midRight.rotateFor(time, timeUnits::sec);
//     // backRight.rotateFor(time, timeUnits::sec);
// 
//     // frontLeft.spin(directionType::fwd); //frontLeft fwd goes backwards
//     // frontRight.spin(directionType::fwd); //frontRight fwd goes backwards
// 
// 
//     // THESE RUN SIMULTANEOUSLY
//     // frontLeft.rotateFor(360, rotationUnits::deg, false);
//     // frontRight.rotateFor(360, rotationUnits::deg);
// 
//     // liftRight.rotateFor(time, timeUnits::sec);
//     // liftLeft.rotateFor(time, timeUnits::sec);
// 
//     // liftRight.rotateFor(90, rotationUnits::deg, false);
//     // liftLeft.rotateFor(90, rotationUnits::deg);
// 
// 
//     /* THESE RUN SIMULTANEOUSLY
//     liftRight.rotateTo(30, rotationUnits::deg, false);
//     liftLeft.rotateTo(30, rotationUnits::deg);
// 
//     task::sleep(3000);
// 
//     liftRight.rotateTo(-30, rotationUnits::deg, false);
//     liftLeft.rotateTo(-30, rotationUnits::deg);
//     // END SIMULTANEOUSLY  */
// 
//     // int count = 0;
//    
//     // while(1) {
//     //     Brain.Screen.printAt( 10, 50, "Hello V5 %d", count++ );
//     //     // Allow other tasks to run
//     //     this_thread::sleep_for(10);
//     // }
// }
// 
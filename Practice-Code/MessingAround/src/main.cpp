/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       lara                                                      */
/*    Created:      Thu Oct 03 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "String.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
motor testingMotor = motor(PORT1, true);

bumper bumperB = bumper(Brain.ThreeWirePort.B);
limit limitA = limit(Brain.ThreeWirePort.A);

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

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

    //testing motors
    // Brain.Screen.print("hello world");
    // testingMotor.rotateFor(3, sec);
    // Brain.Screen.print(testingMotor.rotation(deg));
    // Brain.Screen.print("Done spinning");

    //making a for loop
    // Brain.Screen.print("Beginning program");
    // Brain.Screen.newLine();

    // int rotUnits = 0;
    // for(int i = 0; i < 5; i++) {
    //   rotUnits = testingMotor.rotation(deg);
    //   Brain.Screen.print("This axel has rotated %d degrees", rotUnits);
    //   Brain.Screen.newLine();
    //   testingMotor.rotateFor(2,sec);
    // }

    // Brain.Screen.print("Total full rotations is %d", rotUnits%365);
    // Brain.Screen.newLine();

    // Brain.Screen.print("End of program");
    // Brain.Screen.newLine();

    //bumper & limit switch code
    Brain.Screen.print("Beginning program");
    Brain.Screen.newLine();
    while(!bumperB.pressing()) {
        while(limitA.pressing()) {
          testingMotor.spin(fwd);
          int rotUnits = testingMotor.rotation(deg);
          Brain.Screen.print("Number of full rotations = %d", rotUnits%365);
          Brain.Screen.newLine();
        }
    }
    Brain.Screen.print("End of program");
    Brain.Screen.newLine();

    // //Set up callbacks for autonomous and driver control periods.
    // Competition.autonomous( autonomous );
    // Competition.drivercontrol( usercontrol );
    
    // //Run the pre-autonomous function. 
    // pre_auton();
       
    // //Prevent main from exiting with an infinite loop.                        
    // while(1) {
    //   vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    // }    
       
}
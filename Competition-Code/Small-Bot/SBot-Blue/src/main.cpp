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

// define your global instances of motors and other devices here
vex::motor frontLeft(vex::PORT15, vex::gearSetting::ratio18_1, false);
vex::motor midLeft(vex::PORT13, vex::gearSetting::ratio18_1, false);
vex::motor backLeft(vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor frontRight(vex::PORT16, vex::gearSetting::ratio18_1, true);
vex::motor midRight(vex::PORT14, vex::gearSetting::ratio18_1, true);
vex::motor backRight(vex::PORT12, vex::gearSetting::ratio18_1, true);
vex::motor liftLeft(vex::PORT18, vex::gearSetting::ratio18_1, true);
vex::motor liftRight(vex::PORT17, vex::gearSetting::ratio18_1, false);



int main() {

    // Test run -- move a little bit
    double time = 3;
    
    // frontLeft.rotateFor(time, vex::timeUnits::sec);
    // midLeft.rotateFor(time, vex::timeUnits::sec);
    // backLeft.rotateFor(time, vex::timeUnits::sec);
    // frontRight.rotateFor(time, vex::timeUnits::sec);
    // midRight.rotateFor(time, vex::timeUnits::sec);
    // backRight.rotateFor(time, vex::timeUnits::sec);

    liftRight.rotateFor(time, vex::timeUnits::sec);
    liftLeft.rotateFor(time, vex::timeUnits::sec);

    // int count = 0;
   
    // while(1) {
    //     Brain.Screen.printAt( 10, 50, "Hello V5 %d", count++ );
    //     // Allow other tasks to run
    //     this_thread::sleep_for(10);
    // }
}

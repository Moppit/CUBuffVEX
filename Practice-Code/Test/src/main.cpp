/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\insar                                            */
/*    Created:      Thu Oct 03 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::motor LeftMotor (vex::PORT1, vex::gearSetting::ratio18_1, false);
//vex::motor RightMotor (vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::bumper click(Brain.ThreeWirePort.B);
vex::bumper bum = vex::bumper(Brain.ThreeWirePort.B);

vex::rotationUnits rotations = vex::rotationUnits::rev;
vex::directionType direction = vex::directionType::fwd;
// define your global instances of motors and other devices here

int main(){
    //The robot continually checks if the Bumper Switch is pressed and runs the robot forward if the Bumper Switch is pressed. 
    //However, it will never stop spinning the motors.
    while(true){
        // Brain.Screen.newLine();
        // Brain.Screen.print(click.value());
        if(click.pressing() || bum.pressing() ||bum.value() || click.value()){
            LeftMotor.spin(directionType::fwd);
            //RightMotor.spin(directionType::fwd);
            Brain.Screen.print("Ouch");
        }
    }
}

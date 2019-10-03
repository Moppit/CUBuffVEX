/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       michelletran                                              */
/*    Created:      Thu Oct 03 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::motor m1(vex::PORT1, vex::gearSetting::ratio18_1, false);

// define your global instances of motors and other devices here


int main() {
    m1.setRotation(0, deg);
    while(m1.rotation(deg) < 360)
    {
      m1.rotateFor(fwd, 20, deg);
      Brain.Screen.print("Rotation value: %d", m1.rotation(deg));
    }
}

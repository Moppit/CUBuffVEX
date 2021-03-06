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
vex::bumper bumpBoi = Brain.ThreeWirePort.B;
vex::limit limBoi = Brain.ThreeWirePort.A;

// define your global instances of motors and other devices here


int main() {
    int countB = 0;
    int countL = 0;
    while(1)
    {
      if(bumpBoi.pressing())
      {
        Brain.Screen.print("Button has been pressed %d times", countB);
        Brain.Screen.newLine();
        countB++;
      }
      if(limBoi.pressing())
      {
        Brain.Screen.print("Limit switch has been pressed %d times", countL);
        Brain.Screen.newLine();
        countL++;
      }
    }
    // The following code is very rickety -- turning is not smooth
    // while(m1.rotation(deg) < 360)
    // {
    //   m1.rotateFor(fwd, 20, deg);
    //   Brain.Screen.print("Rotation value: %d", m1.rotation(deg));
    // }
}

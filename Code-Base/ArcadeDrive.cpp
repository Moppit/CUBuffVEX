// drives each side on independent powers
// 8/23/19: arcadeDrive() is the same as DriveTrain::driveRobot()
void arcadeDrive(double leftPower, double rightPower){
    num_motors = leftMotors.size()
    for(int i = 0; i < num_motors; i++) {
        leftMotors[i].spin(vex::directionType::fwd, leftPower, vex::velocityUnits::rpm);
        rightMotors[i].spin(vex::directionType::fwd, rightPower, vex::velocityUnits::rpm);
    }
}

// Need to check what the left and right values are
double driveY = double(Controller.Axis3.value());
double driveX = double(Controller.Axis1.value())/2;
// NOTE: the chassis object is of type DriveTrain
DriveTrain chassis;
chassis.arcadeDrive(driveY + driveX, driveY - driveX);

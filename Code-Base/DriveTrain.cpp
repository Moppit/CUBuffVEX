// ******************* DRIVE TRAIN CLASS *******************
class DriveTrain{
    private:
        //we commented out components that are not yet attached
        vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.A);
        vector<vex::motor> leftMotors;
        vector<vex::motor> rightMotors;
        //vex::encoder leftEncoder;
        //vex::encoder rightEncoder;
    public:
        DriveTrain(); // Default constructor
        DriveTrain(vex::motor leftFront, vex::motor leftBack, vex::motor rightFront, vex::motor rightBack); //constructor for a four wheeled machine
        DriveTrain(vex::motor leftFront, vex::motor leftMiddle, vex::motor leftBack, vex::motor rightFront, vex::motor rightMiddle, vex::motor rightBack); //constructor for a six wheeled machine
        void setLeftMotors(double); // Sets all left motors to given param
        void setRightMotors(double); // Sets all right motors to given param
        double getGyroAngle(); // Returns gyro angle
        void resetGyro(); // Resets gyro angle
        double getRightInches();
        double getLeftInches();
        void stopDriveMotors(); //goes through each motor in the vector leftMotors and rightMotors and stop all motors
        void driveRobot(double leftPower, double rightPower);
        void moveForward(double power); //sets all drive motors to move forward
        void moveBackward(double power); //sets all drive motors to move backward
        void turnRight(double power); //sets all drive motors to turn right
        void turnLeft(double power); //sets all drive motors to turn left
};

// Default Constructor
DriveTrain::DriveTrain(){
    Brain.Screen.print("Drive train has been instantiated.");
    Brain.Screen.newLine();
}

//four motor drive train
DriveTrain::DriveTrain(vex::motor leftFront, vex::motor leftBack, vex::motor rightFront, vex::motor rightBack) {
    leftMotors.push_back(leftFront);
    leftMotors.push_back(leftBack);
    rightMotors.push_back(rightFront);
    rightMotors.push_back(rightBack);
}

//six motor drive train
DriveTrain::DriveTrain(vex::motor leftFront, vex::motor leftMiddle, vex::motor leftBack, vex::motor rightFront, vex::motor rightMiddle, vex::motor rightBack) {
    leftMotors.push_back(leftFront);
    leftMotors.push_back(leftMiddle);
    leftMotors.push_back(leftBack);
    rightMotors.push_back(rightFront);
    rightMotors.push_back(rightMiddle);
    rightMotors.push_back(rightBack);
}

void DriveTrain::setLeftMotors(double rotationVal){
    // Iterate through each of the motors
    for(int i = 0; i < leftMotors.size(); i++){
        // Set rotation of motor to desired value - currently using revoluations as units
        leftMotors[i].setRotation(rotationVal, vex::rotationUnits::rev);
    }
}
void DriveTrain::setRightMotors(double rotationVal){
    // Iterate through each of the motors
    for(int i = 0; i < rightMotors.size(); i++){
        // Set rotation of motor to desired value - currently using revoluations as units
        rightMotors[i].setRotation(rotationVal, vex::rotationUnits::rev);
    }
}

//do not return 0
double DriveTrain::getGyroAngle(){
    // Currently set to returning rotation units in revolutions - subject to change
    return Gyro.value(vex::rotationUnits::deg);
}

//we had to comment this function out because we don't have a gyro
void DriveTrain::resetGyro(){
    // The below does not calibrate the gyro -- need to look into changing gyro value
    Gyro.isCalibrating();
    Brain.Screen.print("Gyro finished calibrating");
    Brain.Screen.newLine();
}
double DriveTrain::getRightInches(){
    // Not sure what to return here
    return 0;
}
double DriveTrain::getLeftInches(){
    // Not sure what to return here
    return 0;
}

//stops all drive motors
void DriveTrain::stopDriveMotors() {
    for(int i = 0; i < rightMotors.size(); i++) {
        leftMotors[i].stop();
        rightMotors[i].stop();
    }
}

// drives each side on independent powers
void DriveTrain::driveRobot(double leftPower, double rightPower){
    for(int i = 0; i <leftMotors.size(); i++) {
        leftMotors[i].spin(vex::directionType::fwd, leftPower, vex::velocityUnits::rpm);
        rightMotors[i].spin(vex::directionType::fwd, rightPower, vex::velocityUnits::rpm);
    }
}

//moves drive motors forward at a specific power
void DriveTrain::moveForward(double power){
    for(int i = 0; i <leftMotors.size(); i++) {
        leftMotors[i].spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);
        rightMotors[i].spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);
    }
}

//moves drive motors backward at a specific power
void DriveTrain::moveBackward(double power){
    for(int i = 0; i <leftMotors.size(); i++) {
        leftMotors[i].spin(vex::directionType::fwd, -power, vex::velocityUnits::rpm);
        rightMotors[i].spin(vex::directionType::fwd, -power, vex::velocityUnits::rpm);
    }
}

//turns drive motors right at a specific power
//however, the parameter used to be angle, goal: change back to angle someday
void DriveTrain::turnRight(double power){
    for(int i = 0; i <leftMotors.size(); i++) {
        leftMotors[i].spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);
        rightMotors[i].spin(vex::directionType::fwd, -power, vex::velocityUnits::rpm);
    }
}

//turns drive motors left at a specific power
//however, the parameter used to be angle, goal: change back to angle someday
void DriveTrain::turnLeft(double power){
    for(int i = 0; i <leftMotors.size(); i++) {
        leftMotors[i].spin(vex::directionType::fwd, -power, vex::velocityUnits::rpm);
        rightMotors[i].spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);
    }
}

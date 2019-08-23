/************ PROPORTIONAL, INTEGRAL, DERIVATIVE (PID) CLASS ************
* The PID method essentially allows the robot to adjust its position in order
* to eventually reach the desired position.
*/
class PID{
    private:
        double P;
        double I;
        double D;
        double goal;
        double errorSum;
        double lastError;
    public:
        PID(double, double, double); // Parametized constructor
        void setGoal(double); // Set target distance
        double getError(double); // Returns the distance from the goal
        double getPower(double); // Uses PID equation to calculate next power output
};
PID::PID(double p, double i, double d){
    P = p;
    I = i;
    D = d;
    goal = 0;
    errorSum = 0;
    lastError = 0;
}
void PID::setGoal(double newGoal){
    goal = newGoal;
}
double PID::getError(double currentVal){
    return goal-currentVal;
}
double PID::getPower(double currentVal){
    double error = getError(currentVal);
    errorSum += error;
    double errorChange = error - lastError;
    lastError = error;
    return P*error + I*errorSum + D*errorChange;
}

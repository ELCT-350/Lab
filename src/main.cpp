#include <iostream> //places contents of iostream header here (includes definitions of classes and functions which
#include <fstream> //file i/o streams
#include "Sinusoidal.h"
#include "DerivativeBlock.h"
#include "IntegralBlock.h"
#include "Sum.h"
#include "Gain.h"
#include "Constant.h"

using namespace std; //indicates that we will be using types declared under the std (standard) namespace.
                     //Namespaces are used to avoid name collisions. Think of them like lastnames. Two people can be
                     //called John, and you differentiate them by their lastname. Two types can have the same name if
                     //are in separate namespaces.

using namespace Morgan;

/**
 * The entry point function is the function that is automatically called when the executable is run. In C++ its
 * signature is such that it returns an integer, and takes in an integer and an array of strings as arguments.
 * These are the command-line arguments invoked when running the program.
 *
 * @param[in] argc the number of command-line arguments (will be at least 1)
 * @param[in] argv an array containing the command-line arguments (the 0th value in the array will always be the
 * program name
 *
 * @return the error code (if the program exited cleanly, it should return 0. Otherwise, return an integer
 * corresponding to the error that occurred.
 **/


int main(int argc, char* argv[])
{
    ifstream input("config/input.txt");
    double stopTime, timeStep;
    double amplitude, frequency, phase, offset;
    input >> stopTime >> timeStep
        >> amplitude >> frequency >> phase >> offset;
    DerivativeBlock Derivative;
    IntegralBlock Integral;
    Constant theconstant;
    Constant kp;
    Constant ki;
    Constant kd;
    Gain gain;
    Sum sum;

    double x = 4.0;

    ofstream output("output.csv");
    output << "Time,X" << endl;

    for (double time = 0.0; time <= stopTime; time += timeStep)
    {
        gain.setPortValue(Gain::Input, x);
        gain.step(time, timeStep);

        theconstant.setParameter(Constant::value, 10.0);
        theconstant.step(time, timeStep);

        sum.setPortValue(Sum::Input1, gain.getPortValue(Gain::Output));
        sum.setPortValue(Sum::Input2, theconstant.getPortValue(Constant::Output));
        sum.step(time, timeStep);

        Integral.setPortValue(IntegralBlock::Input, sum.getPortValue(Sum::Output));
        Integral.step(time, timeStep);

        x = x + Integral.getPortValue(IntegralBlock::Output);

        cout << "time; " << time << endl;
        cout << "x: " << x << endl;
        output << time << ',' << x << endl;

    }
    return 0;
}

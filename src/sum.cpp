#include <cmath>
#include "Sum.h"

using namespace Morgan;
Sum::Sum()
    :SignalBlock(0, 3)
{

}


void Sum::step(double time, double timeStep)
{
    setPortValue(Output, getPortValue(Input1) + getPortValue(Input2));
}
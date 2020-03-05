#include <cmath>
#include "Gain.h"

using namespace Morgan;
Gain::Gain()
    :SignalBlock(0, 2), _Gain(-5.0)
{

}


void Gain::step(double time, double timeStep)
{


    setPortValue(Output, getPortValue(Input) * _Gain);
}
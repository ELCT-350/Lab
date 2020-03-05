#include <cmath>
#include "Constant.h"

using namespace Morgan;
Constant::Constant()
    :SignalBlock(1, 2), _Theconstant(10.0)
{

}


void Constant::step(double time, double timeStep)
{


    setPortValue(Output, getParameter(value));
}
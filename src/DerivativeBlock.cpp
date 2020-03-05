#include <cmath>
#include "DerivativeBlock.h"

using namespace Morgan;
DerivativeBlock::DerivativeBlock()
    :SignalBlock(0, 2), _previousInput(0.0)
{

}


void DerivativeBlock::step(double time, double timeStep)
{
    setPortValue(Output, (getPortValue(Input) - _previousInput) / timeStep);
    _previousInput = getPortValue(Input);

}
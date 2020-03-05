#include <cmath>
#include "IntegralBlock.h"

using namespace Morgan;
IntegralBlock::IntegralBlock()
    :SignalBlock(0, 2), _area(0.0)
{

}


void IntegralBlock::step(double time, double timeStep)
{

    _area = getPortValue(Input) * timeStep;
    setPortValue(Output, _area);
}
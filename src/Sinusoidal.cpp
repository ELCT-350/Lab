#include <cmath>
#include "Sinusoidal.h"

using namespace Morgan;

double sinusoidal(double time, double amplitude, double frequency, double phase, double offset)
{
    frequency *= 2 * 3.14;
    phase *= 3.14 / 180;
    return amplitude * sin(frequency * time + phase) + offset;
}

Sinusoidal::Sinusoidal(double amplitude, double frequency, double phase, double offset)
    : SignalBlock(4, 1)
{
    setParameter(Amplitude, amplitude);
    setParameter(Frequency, frequency * 2.0 * 3.14);
    setParameter(Phase, phase * 3.14 / 180.0);
    setParameter(Offset, offset);
}

void Sinusoidal::step(double time, double timeStep)
{
    setPortValue(Output, getParameter(Amplitude) *
        sin(getParameter(Frequency) * time + getParameter(Phase)) +
        getParameter(Offset));
}
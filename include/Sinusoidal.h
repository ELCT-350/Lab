#pragma once
#include "SignalBlock.h"

namespace Morgan
{
    class Sinusoidal : public ELCT350::SignalBlock
    {
    public:
        enum Parameters : size_t
        {
            Amplitude,
            Frequency,
            Phase,
            Offset
        };

        enum Ports : size_t
        {
            Output
        };

        Sinusoidal(double amplitude, double frequency, double phase, double offset);
        virtual void step(double time, double timeStep) override;
    };
}
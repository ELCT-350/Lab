#pragma once
#include "SignalBlock.h"

namespace Morgan
{
    class Gain : public ELCT350::SignalBlock
    {
    public:
        enum Ports : size_t
        {
            Input,
            Output
        };
        Gain();
        virtual void step(double time, double timeStep) override;
    private:
        double _Gain;
    };
}
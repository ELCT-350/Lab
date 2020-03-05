#pragma once
#include "SignalBlock.h"

namespace Morgan
{
    class Sum : public ELCT350::SignalBlock
    {
    public:
        enum Ports : size_t
        {
            Input1,
            Input2,
            Output
        };
        Sum();
        virtual void step(double time, double timeStep) override;
    };
}
#pragma once
#include "SignalBlock.h"

namespace Morgan
{
    class DerivativeBlock : public ELCT350::SignalBlock
    {
    public:
        enum Ports : size_t
        {
            Input,
            Output
        };

        DerivativeBlock();
        virtual void step(double time, double timeStep) override;
    private:
        double _previousInput;
    };
}
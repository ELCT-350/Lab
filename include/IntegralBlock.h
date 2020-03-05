#pragma once
#include "SignalBlock.h"

namespace Morgan
{
    class IntegralBlock : public ELCT350::SignalBlock
    {
    public:
        enum Ports : size_t
        {
            Input,
            Output
        };

        IntegralBlock();
        virtual void step(double time, double timeStep) override;
    private:
        double _area;
    };
}
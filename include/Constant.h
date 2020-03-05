#pragma once
#include "SignalBlock.h"

namespace Morgan
{
    class Constant : public ELCT350::SignalBlock
    {
    public:

        enum Ports : size_t
        {
            Input,
            Output
        };
        enum Parameters : size_t
        {
            value
        };
        Constant();
        virtual void step(double time, double timeStep) override;
    private:
        double _Theconstant;
    };
}
#include "SignalBlock.h"

using namespace ELCT350;

SignalBlock::SignalBlock(size_t numParameters, size_t numPorts)
{
  for (size_t parameterIndex = 0; parameterIndex < numParameters; ++parameterIndex)
  {
    _parameters.push_back(0.0);
  }

  //TODO: Create for loop for ports
}

void SignalBlock::setParameter(size_t parameterIndex, double parameter)
{
  _parameters[parameterIndex] = parameter;
}

double SignalBlock::getParameter(size_t parameterIndex) const
{
  return _parameters.at(parameterIndex);
}

void SignalBlock::setPortValue(size_t portIndex, double portValue)
{
  //TODO: Implement this
}

double SignalBlock::getPortValue(size_t portIndex) const
{
  return 0.0; //TODO: return port value
}
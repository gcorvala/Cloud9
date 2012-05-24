#include "Range.h"

#include <math.h>

Range::Range (Float32 min, Float32 max, Float32 step)
  :m_min (min)
  ,m_max (max)
  ,m_step (step)
{
}

Range::~Range ()
{
}

Float32
Range::getMin () const
{
  return m_min;
}

void
Range::setMin (Float32 min)
{
  m_min = min;
}

Float32
Range::getMax () const
{
  return m_max;
}

void
Range::setMax (Float32 max)
{
  m_max = max;
}

Float32
Range::getStep () const
{
  return m_step;
}

void
Range::setStep (Float32 step)
{
  m_step = step;
}

UInt32
Range::getSteps () const
{
  return floor ((m_max-m_min)/m_step) + 1;
}

UInt32
Range::getValueIndex (Float32 value) const
{
  return floor ((value-m_min)/m_step) + 1;
}
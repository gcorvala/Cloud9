#include "Range.h"

#include <math.h>

Range::Range (Float32 min, Float32 max, UInt32 steps)
  :m_min (min)
  ,m_max (max)
  ,m_steps (steps)
{
  ASSERT (m_min <= m_max, "min >= max");
  ASSERT (m_steps > 0, "steps == 0");
}

Range::~Range ()
{
}

Boolean
Range::operator== (const Range& r) const
{
  return (m_min == r.m_min) && (m_max == r.m_max) && (m_steps == r.m_steps);
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

UInt32
Range::getSteps () const
{
  return m_steps;
}

void
Range::setSteps (UInt32 steps)
{
  m_steps = steps;
}

Float32
Range::getStep () const
{
  return (m_max - m_min) / m_steps;
}

UInt32
Range::getValueIndex (Float32 value) const
{
  ASSERT (contains (value), "value is out of range");

  return floor ((value - m_min) / (m_max - m_min) * m_steps);
}

Boolean
Range::contains (Float32 value) const
{
  return (value >= m_min && value < m_max);
}

Interval
Range::operator[] (UInt32 index) const
{
  Float32 start = index * getStep () + m_min;
  Float32 end = (index + 1) * getStep () + m_min;
  return Interval (start, end);
}
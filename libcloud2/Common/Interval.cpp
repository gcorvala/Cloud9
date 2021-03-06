#include "Interval.h"

Interval::Interval (Float32 min, Float32 max)
  :m_min (min)
  ,m_max (max)
{
  ASSERT (m_min <= m_max, "min > max");
}

Interval::~Interval ()
{
}

Float32
Interval::getMin () const
{
  return m_min;
}

void
Interval::setMin (Float32 min)
{
  ASSERT (min <= m_max, "min > max");

  m_min = min;
}

Float32
Interval::getMax () const
{
  return m_max;
}

void
Interval::setMax (Float32 max)
{
  ASSERT (max >= m_min, "min > max");

  m_max = max;
}

Float32
Interval::getLength () const
{
  return m_max - m_min;
}

Float32
Interval::getCenter () const
{
  return (m_max + m_min) / 2.;
}

Boolean
Interval::contains (Float32 value) const
{
  return (value >= m_min && value <= m_max);
}
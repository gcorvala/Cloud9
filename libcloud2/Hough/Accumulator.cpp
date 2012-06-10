#include "Accumulator.h"

Accumulator::Accumulator ()
{
}

Accumulator::~Accumulator ()
{
}

UInt32
Accumulator::getDimension () const
{
  return m_ranges.size ();
}

std::vector <UInt32>
Accumulator::getDimensions () const
{
  std::vector <UInt32> dimensions;

  for (UInt32 i = 0; i < m_ranges.size (); ++i) {
    dimensions.push_back (m_ranges[i].getSteps ());
  }

  return dimensions;
}

const std::vector <Range>&
Accumulator::getRanges () const
{
  return m_ranges;
}
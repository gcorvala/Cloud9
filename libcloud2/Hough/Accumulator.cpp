#include "Accumulator.h"

#include <algorithm>
#include <math.h>

Accumulator::Accumulator (const std::vector <Range>& ranges)
{
  m_ranges = ranges;
  init ();
}

Accumulator::~Accumulator ()
{
}

void
Accumulator::clear ()
{
  init ();
}

std::vector <Range>
Accumulator::getRanges () const
{
  return m_ranges;
}

void
Accumulator::setRanges (const std::vector <Range>& ranges)
{
  m_ranges = ranges;
  init ();
}

void
Accumulator::findMaxima (Float32 threshold, std::vector <Float32>& maxima_values, std::vector < std::vector <UInt32> >& maxima_voter_ids) const
{
  std::vector <AccumulatorCell>::const_iterator it;
  Float32 value;
  std::vector <UInt32> voter_ids;
  std::vector <AccumulatorCell> space;

  space = m_space;

  maxima_values.clear ();
  maxima_voter_ids.clear ();

  while (true) {
    it = max_element (space.begin (), space.end (), Accumulator::cellComparator);
    value = it->getValue ();
    PRINT (value);

    if (value < threshold) {
      break;
    }
    else {
      it->getVoterIds (voter_ids);
      maxima_values.push_back (value);
      maxima_voter_ids.push_back (voter_ids);
      
      for (int i = 0; i < voter_ids.size (); ++i) {
        for (int j = 0; j < space.size (); ++j) {
          space[j].removeId (voter_ids[i]);
        }
      }
    }
  }
}

void
Accumulator::vote (const AccumulatorVote& vote)
{
  UInt32 idx = 0;
  UInt32 size = 1;

  for (UInt8 i = 0; i < vote.getDimension (); ++i) {
    UInt32 parameter = m_ranges[i].getValueIndex (vote[i]);
    parameter *= size;
    size *= m_ranges[i].getSteps ();
    idx += parameter;
  }

  m_space[idx].addVote (vote);
}

Float32
Accumulator::getValue (const std::vector <UInt32>& parameters)
{
  UInt32 idx = 0;
  UInt32 size = 1;

  for (UInt8 i = 0; i < parameters.size (); ++i) {
    UInt32 parameter = parameters[i];
    parameter *= size;
    size *= m_ranges[i].getSteps ();
    idx += parameter;
  }
  return m_space[idx].getValue ();
}

void
Accumulator::init ()
{
  UInt32 size = 1;

  for (UInt32 i = 0; i < m_ranges.size (); ++i) {
    size *= m_ranges[i].getSteps ();
  }

  m_space.clear ();
  m_space.resize (size);

  PRINT (m_space.size ());
}

Boolean
Accumulator::cellComparator (const AccumulatorCell& c1, const AccumulatorCell& c2)
{
  return c1.getValue () < c2.getValue ();
}
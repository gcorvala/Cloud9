#include "Accumulator.h"

#include <algorithm>
#include <math.h>

Accumulator::Accumulator (const std::vector <Range>& ranges)
{
  m_ranges = ranges;
  init ();
}

Accumulator::Accumulator (const std::vector <Float32> min, const std::vector <Float32> max, const std::vector <Float32> bin_size)
  :m_min (min)
  ,m_max (max)
  ,m_bin_size (bin_size)
{
  // FIXME: check min, max & bin sizes (equals)
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

void
Accumulator::setMin (const std::vector <Float32> min)
{
  m_min = min;
}

const std::vector <Float32>
Accumulator::getMin () const
{
  return m_min;
}

void
Accumulator::setMax (const std::vector <Float32> max)
{
  m_max = max;
}

const std::vector <Float32>
Accumulator::getMax () const
{
  return m_max;
}

void
Accumulator::setBinSize (const std::vector <Float32> bin_size)
{
  m_bin_size = m_bin_size;
}

const std::vector <Float32>
Accumulator::getBinSize () const
{
  return m_bin_size;
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
  std::vector <UInt32> parameters;
  std::vector <UInt32> p_sizes;
  UInt32 idx = 0;

  p_sizes.push_back (1);

  for (UInt8 i = 0; i < vote.getDimension (); ++i) {
    UInt32 parameter = m_ranges[i].getValueIndex (vote[i]);
    UInt32 p_size = m_ranges[i].getSteps ();
    parameters.push_back (parameter);
    p_sizes.push_back (p_size);
    idx += p_sizes[i]*parameter;
  }

  m_space[idx].addVote (vote);
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
}

Boolean
Accumulator::cellComparator (const AccumulatorCell& c1, const AccumulatorCell& c2)
{
  return c1.getValue () < c2.getValue ();
}
#include "Accumulator2D.h"

Accumulator2D::Accumulator2D (const std::vector <Range>& ranges)
{
  m_ranges = ranges;
  alloc ();
  reset ();
}

Accumulator2D::Accumulator2D (const Range& r1, const Range& r2)
{
  m_ranges.push_back (r1);
  m_ranges.push_back (r2);

  alloc ();
  reset ();
}

Accumulator2D::Accumulator2D (const Accumulator2D& accumulator)
{
  PRINT ("")
  m_ranges = accumulator.m_ranges;
  alloc ();
  for (UInt32 i = 0; i < m_ranges[0].getSteps (); ++i) {
    for (UInt32 j = 0; j < m_ranges[1].getSteps (); ++j) {
      m_space[i][j] = accumulator.m_space[i][j];
    }
  }
}

Accumulator2D::~Accumulator2D ()
{
  free ();
}

Accumulator&
Accumulator2D::operator= (const Accumulator& accumulator)
{
  PRINT ("debug1");
  const Accumulator2D& accumulator_2d = dynamic_cast <const Accumulator2D&> (accumulator);

  return operator= (accumulator_2d);
}

Accumulator2D&
Accumulator2D::operator= (const Accumulator2D& accumulator)
{
  PRINT ("debug2");
  m_ranges = accumulator.m_ranges;
  free ();
  alloc ();
  for (UInt32 i = 0; i < m_ranges[0].getSteps (); ++i) {
    for (UInt32 j = 0; j < m_ranges[1].getSteps (); ++j) {
      m_space[i][j] = accumulator.m_space[i][j];
    }
  }
  
  return *this;
}

Accumulator&
Accumulator2D::operator-= (const Accumulator& accumulator)
{
  PRINT ("ok1");
  const Accumulator2D& accumulator_2d = dynamic_cast <const Accumulator2D&> (accumulator);
  ASSERT (std::equal (m_ranges.begin (), m_ranges.end (), accumulator_2d.m_ranges.begin ()), "not same ranges");
  operator-= (accumulator_2d);
}

Accumulator2D&
Accumulator2D::operator-= (const Accumulator2D& accumulator)
{
  PRINT ("ok2");
  PRINT (m_ranges.size ());
  PRINT (accumulator.m_ranges.size ());
  ASSERT (std::equal (m_ranges.begin (), m_ranges.end (), accumulator.m_ranges.begin ()), "not same ranges");

  for (UInt32 i = 0; i < m_ranges[0].getSteps (); ++i) {
    for (UInt32 j = 0; j < m_ranges[1].getSteps (); ++j) {
      m_space[i][j] -= accumulator.m_space[i][j];
    }
  }

  return *this;
}

Accumulator::ptr
Accumulator2D::copy () const
{
  return new Accumulator2D (*this);
}

UInt32
Accumulator2D::getValue (const Indices& parameters) const
{
  ASSERT (parameters.size () == getDimension (), "parameters does not match accumulator dimension");

  return m_space[parameters[0]][parameters[1]];
}

void
Accumulator2D::vote (const ModelCoefficients& coeffs)
{
  ASSERT (coeffs.getSize () == getDimension (), "ModelCoefficients does not match accumulator dimension");

  ++m_space[m_ranges[0].getValueIndex (coeffs[0])][m_ranges[1].getValueIndex (coeffs[1])];
}

Indices
Accumulator2D::getMaxValue () const
{
  Indices result (2);
  UInt32 max = 0;

  for (UInt32 i = 0; i < m_ranges[0].getSteps (); ++i) {
    for (UInt32 j = 0; j < m_ranges[1].getSteps (); ++j) {
      if (m_space[i][j] > max) {
        max = m_space[i][j];
        result[0] = i;
        result[1] = j;
      }
    }
  }
  
  PRINT (max);

  return result;
}

void
Accumulator2D::alloc ()
{
  m_space = new UInt32* [m_ranges[0].getSteps ()];
  for (UInt32 i = 0; i < m_ranges[0].getSteps (); ++i) {
    m_space[i] = new UInt32 [m_ranges[1].getSteps ()];
  }
}

void
Accumulator2D::free ()
{
  for (UInt32 i = 0; i < m_ranges[0].getSteps (); ++i) {
    delete [] m_space[i];
  }
  delete [] m_space;
}

void
Accumulator2D::reset ()
{
  for (UInt32 i = 0; i < m_ranges[0].getSteps (); ++i) {
    for (UInt32 j = 0; j < m_ranges[1].getSteps (); ++j) {
      m_space[i][j] = 0;
    }
  }
}
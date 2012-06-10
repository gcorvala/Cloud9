#include "FilterIndices.h"

FilterIndices::FilterIndices ()
  :m_negative (false)
{
}

FilterIndices::~FilterIndices ()
{
}

void
FilterIndices::compute (PointCloud3D& output) const
{
  Indices indices;

  output.clear ();

  compute (indices);

  for (Indices::const_iterator it = indices.begin (); it != indices.end (); ++it) {
    output += this->operator[] (*it);
  }
}

void
FilterIndices::compute (const PointCloud3D& input, Indices& indices)
{
  setInputCloud (input);
  compute (indices);
}

Boolean
FilterIndices::getNegative () const
{
  return m_negative;
}

void
FilterIndices::setNegative (Boolean negative)
{
  m_negative = negative;
}

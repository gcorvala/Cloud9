#include "ExtractIndices.h"

#include <algorithm>

ExtractIndices::ExtractIndices ()
{
}

ExtractIndices::~ExtractIndices ()
{
}

void
ExtractIndices::compute (Indices &indices) const
{
  Indices::const_iterator it;

  indices.clear ();

  it = m_extract_indices.begin ();

  for (UInt32 i = 0; i < getInputSize (); ++i) {
    UInt32 idx = getInputIndex (i);
    if (it != m_extract_indices.end () && *it == idx) {
      ++it;
      if (!m_negative) {
        indices.push_back (idx);
      }
    }
    else if (m_negative) {
      indices.push_back (idx);
    }
  }
}

const Indices&
ExtractIndices::getExtractIndices () const
{
  return m_extract_indices;
}

void
ExtractIndices::setExtractIndices (const Indices& indices)
{
  m_extract_indices = indices;
  std::sort (m_extract_indices.begin (), m_extract_indices.end ());
}
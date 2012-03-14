#ifndef __EXTRACT_INDICES_T_H__
#define __EXTRACT_INDICES_T_H__

#include "FilterT.h"

#include <algorithm>

template <class PointT>
class ExtractIndicesT : public FilterT <PointT> {
  public:
    ExtractIndicesT ();
    virtual ~ExtractIndicesT ();

    void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const;

    PointIndices getIndices () const;
    void setIndices (const PointIndices& indices);

    Boolean getNegative () const;
    void setNegative (Boolean negative);

  protected:
    PointIndices m_indices;
    Boolean m_negative;
};

template <class PointT>
ExtractIndicesT <PointT>::ExtractIndicesT ()
  :m_negative (false)
{
}

template <class PointT>
ExtractIndicesT <PointT>::~ExtractIndicesT ()
{
}

template <class PointT>
void
ExtractIndicesT <PointT>::compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const
{
  PointIndices::const_iterator it;

  output.clear ();

  it = m_indices.begin ();

  for (UInt32 i = 0; i < input.size (); ++i) {
    if (it != m_indices.end () && *it == i) {
      ++it;
      if (!m_negative) {
        output.push_back (input[i]);
      }
    }
    else if (m_negative) {
      output.push_back (input[i]);
    }
  }
}

template <class PointT>
PointIndices
ExtractIndicesT <PointT>::getIndices () const
{
  return m_indices;
}

template <class PointT>
void
ExtractIndicesT <PointT>::setIndices (const PointIndices& indices)
{
  m_indices = indices;
  std::sort (m_indices.begin (), m_indices.end ());
}

template <class PointT>
Boolean
ExtractIndicesT <PointT>::getNegative () const
{
  return m_negative;
}

template <class PointT>
void
ExtractIndicesT <PointT>::setNegative (Boolean negative)
{
  m_negative = negative;
}

#endif
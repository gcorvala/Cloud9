#ifndef __EXTRACT_INDICES_T_H__
#define __EXTRACT_INDICES_T_H__

#include "FilterIndicesT.h"

template <class PointT>
class ExtractIndicesT : public FilterIndicesT <PointT> {
  public:
    typedef std::vector <Float32> ModelCoefficients;

    ExtractIndicesT ();
    virtual ~ExtractIndicesT ();

    Boolean getNegative () const;
    void setNegative (Boolean negative);

  protected:
    Boolean m_negative;
};

template <class PointT>
ExtractIndicesT <PointT>::ExtractIndices ()
  :m_negative (false)
{
}

template <class PointT>
ExtractIndicesT <PointT>::~ExtractIndices ()
{
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
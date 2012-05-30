#include "HoughTransform.h"

HoughTransform::HoughTransform ()
{
}

HoughTransform::~HoughTransform ()
{
}

void
HoughTransform::setInput (const PointCloud3D& cloud)
{
  m_cloud = &cloud;
}

const PointCloud3D&
HoughTransform::getInput () const
{
  return *m_cloud;
}

const Accumulator&
HoughTransform::getAccumulator () const
{
  return m_accumulator;
}
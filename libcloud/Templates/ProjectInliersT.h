#ifndef __PROJECT_INLIERS_T_H__
#define __PROJECT_INLIERS_T_H__

#include "FilterIndicesT.h"

template <class PointT>
class ProjectInliersT : public FilterIndices <PointT> {
  public:
    typedef std::vector <Float32> ModelCoefficients;

    ProjectInliersT ();
    virtual ~ProjectInliersT ();

    void setModelCoefficients (const ModelCoefficients& coefficients);
    ModelCoefficients getModelCoefficients () const;

  protected:
    ModelCoefficients m_coefficients;
};

template <class PointT>
void
ProjectInliersT <PointT>::setModelCoefficients (const ModelCoefficients& coefficients)
{
  m_coefficients = coefficients;
}

template <class PointT>
ModelCoefficients
ProjectInliersT <PointT>::getModelCoefficients () const
{
  return m_coefficients;
}

#endif
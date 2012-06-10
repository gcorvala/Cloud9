#include "HoughTransform.h"

#include "../Filtering/Filter.h"
#include "../Filtering/ExtractIndices.h"

HoughTransform::HoughTransform ()
  :m_accumulator (NULL)
{
}

HoughTransform::HoughTransform (const HoughTransform& hough)
{
  m_accumulator = hough.m_accumulator ? hough.m_accumulator->copy () : NULL;
  m_cloud = hough.m_cloud;
  m_n_values = hough.m_n_values;
  m_min = hough.m_min;
}

HoughTransform::~HoughTransform ()
{
  delete m_accumulator;
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
  return *m_accumulator;
}

void
HoughTransform::findMaxima (Float32 threshold, std::vector <Float32>& maxima_values, std::vector <Indices>& maxima_voter_ids)
{
  Float32 value;
  Indices voter_ids;
  Accumulator::ptr accumulator = m_accumulator->copy ();
  ExtractIndices extractor;
  PointCloud3D inliers, old_cloud, new_cloud;

//  Accumulator::ptr accumulator_backup = m_accumulator;
//  PointCloud3D::const_ptr cloud_backup = m_cloud;

  HoughTransform::ptr hough = this->copy ();

  maxima_values.clear ();
  maxima_voter_ids.clear ();

  UInt8 i = 0;

  old_cloud = *m_cloud;

  while (true) {
    Indices inliers_indices;

    Indices max_indices = accumulator->getMaxValue ();
    PRINT (max_indices[0]);
    PRINT (max_indices[1]);
    getInliers (old_cloud, max_indices, inliers_indices);
    extractor.setInputCloud (old_cloud);
    extractor.setExtractIndices (inliers_indices);
    extractor.setNegative (false);
    extractor.compute (inliers);
    extractor.setNegative (true);
    extractor.compute (new_cloud);
    PRINT (old_cloud.size ());
    old_cloud = new_cloud;
    PRINT (inliers.size ());
    PRINT (new_cloud.size ());
    hough->m_cloud = &inliers;
    hough->m_accumulator->reset ();
    hough->run ();
    *accumulator -= *hough->m_accumulator;
    if (++i == 3)
      break;
  }

  *m_accumulator = *accumulator;
}
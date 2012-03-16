#ifndef __EXTRACT_HOUGH_CLUSTERS_H__
#define __EXTRACT_HOUGH_CLUSTERS_H__

#include "PointCloudT.h"
#include "Point2D.h"
#include "../2D/Matrix.h"

template <typename T>
class ExtractHoughClusters {
  public:
    ExtractHoughClusters ();
    virtual ~ExtractHoughClusters ();

    void compute (const PointCloudT < Point2D <T> >& cloud, std::vector <PointCloudT < Point2D <T> > >& clusters) const;

    Matrix <UInt32> getAccumulator () const;
    void setAccumulator (const Matrix <UInt32>& accumulator);

    std::vector <Float64> getRhoSteps () const;
    void setRhoSteps (std::vector <Float64>& rho_steps);

    std::vector <Float64> getThetaSteps () const;
    void setThetaSteps (std::vector <Float64>& theta_steps);

  protected:
    Float64 m_distance_threshold;
    Matrix <UInt32> m_accumulator;
    std::vector <Float64> m_rho_steps;
    std::vector <Float64> m_theta_steps;
};

template <typename T>
ExtractHoughClusters <T>::ExtractHoughClusters ()
  :m_distance_threshold (10)
{
}

template <typename T>
ExtractHoughClusters <T>::~ExtractHoughClusters ()
{
}

template <typename T>
void
ExtractHoughClusters <T>::compute (const PointCloudT < Point2D <T> >& cloud, std::vector <PointCloudT < Point2D <T> > >& clusters) const
{
  UInt32 max;
  UInt32 theta;
  UInt32 rho;
  Line line;
  LineInliers <T> inliers;
  PointIndices indices;
  PointCloudT < Point2D <T> > cloud_copy;
  PointCloudT < Point2D <T> > cloud_tmp;
  PointCloudT < Point2D <T> > line_cluster;
  Matrix <UInt32> accumulator_copy;
  ExtractIndices < Point2D <T> > extract;
  Hough2D <T> hough;
  LineProjector <T> projector;

  cloud_copy = cloud;
  accumulator_copy = m_accumulator;
  hough.setNTheta (m_theta_steps.size ());
  hough.setNRho (m_rho_steps.size ());
  clusters.clear ();

  inliers.setDistanceThreshold (m_distance_threshold);

  while (true) {
    max = accumulator_copy.max (theta, rho);

    line = Line (m_rho_steps[rho], m_theta_steps[theta]);

    inliers.setLine (line);

    inliers.compute (cloud_copy, indices);

    if (indices.size () < 100) {
      break;
    }

    extract.setIndices (indices);
    extract.setNegative (false);

    extract.compute (cloud_copy, line_cluster);

    extract.setNegative (true);

    extract.compute (cloud_copy, cloud_tmp);

    cloud_copy = cloud_tmp;

    hough.remove (line_cluster, accumulator_copy, m_rho_steps, m_theta_steps);

    projector.setLine (line);
    projector.compute (line_cluster, cloud_tmp);
    line_cluster = cloud_tmp;

    clusters.push_back (line_cluster);
  }
  /*
  max = matrix.max (theta, rho);
  while (true) {
    Line line (rhos[rho], thetas[theta]);
    inliers.setLine (line);
    inliers.setDistanceThreshold (10);

    inliers.compute (cloudT1, indices);

    extract.setIndices (indices);
    extract.setNegative (false);
    extract.compute (cloudT1, cloudT2);
    std::cout << "cloud (+) size: " << cloudT2.size () << std::endl;
    if (cloudT2.size () < 100) break;
    extract.setNegative (true);
    extract.compute (cloudT1, cloudT3);
    std::cout << "cloud (-) size: " << cloudT3.size () << std::endl;
    cloudT1 = cloudT3;

    hough.remove (cloudT2, matrix, rhos, thetas);
    
    pointCloudConverter2 (cloudT2, cloud2);
    viewer.add ("cluster", &cloud2);
    clusters.push_back (cloudT2);
    max = matrix.max (theta, rho);
    std::cout << "max: " << matrix.max () << std::endl;
    */
}

template <typename T>
Matrix <UInt32>
ExtractHoughClusters <T>::getAccumulator () const
{
  return m_accumulator;
}

template <typename T>
void
ExtractHoughClusters <T>::setAccumulator (const Matrix <UInt32>& accumulator)
{
  m_accumulator = accumulator;
}

template <typename T>
std::vector <Float64>
ExtractHoughClusters <T>::getRhoSteps () const
{
  return m_rho_steps;
}

template <typename T>
void
ExtractHoughClusters <T>::setRhoSteps (std::vector <Float64>& rho_steps)
{
  m_rho_steps = rho_steps;
}

template <typename T>
std::vector <Float64>
ExtractHoughClusters <T>::getThetaSteps () const
{
  return m_theta_steps;
}

template <typename T>
void
ExtractHoughClusters <T>::setThetaSteps (std::vector <Float64>& theta_steps)
{
  m_theta_steps = theta_steps;
}

#endif
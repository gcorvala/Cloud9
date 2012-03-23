#ifndef __EXTRACT_HOUGH_CLUSTERS_H__
#define __EXTRACT_HOUGH_CLUSTERS_H__

#include "PointCloudT.h"
#include "Point2D.h"
#include "ExtractEuclideanClusters.h"
#include "../2D/Matrix.h"

template <typename T>
class ExtractHoughClusters {
  public:
    ExtractHoughClusters ();
    virtual ~ExtractHoughClusters ();

    void compute (const PointCloudT < Point2D <T> >& cloud, std::vector <PointCloudT < Point2D <T> > >& clusters, std::vector <Line>& lines) const;

    Float64 getDistanceThreshold () const;
    void setDistanceThreshold (Float64 distance);

    UInt32 getMinPointsPerCluster () const;
    void setMinPointsPerCluster (UInt32 min);

    Matrix <UInt32> getAccumulator () const;
    void setAccumulator (const Matrix <UInt32>& accumulator);

    std::vector <Float64> getRhoSteps () const;
    void setRhoSteps (std::vector <Float64>& rho_steps);

    std::vector <Float64> getThetaSteps () const;
    void setThetaSteps (std::vector <Float64>& theta_steps);

  protected:
    Float64 m_distance_threshold;
    UInt32 m_min_points_per_cluster;
    Matrix <UInt32> m_accumulator;
    std::vector <Float64> m_rho_steps;
    std::vector <Float64> m_theta_steps;
};

template <typename T>
ExtractHoughClusters <T>::ExtractHoughClusters ()
  :m_distance_threshold (10)
  ,m_min_points_per_cluster (10)
{
}

template <typename T>
ExtractHoughClusters <T>::~ExtractHoughClusters ()
{
}

template <typename T>
void
ExtractHoughClusters <T>::compute (const PointCloudT < Point2D <T> >& cloud, std::vector <PointCloudT < Point2D <T> > >& clusters, std::vector <Line>& lines) const
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

  cloud_copy = cloud;
  accumulator_copy = m_accumulator;
  hough.setNTheta (m_theta_steps.size ());
  hough.setNRho (m_rho_steps.size ());
  clusters.clear ();

  inliers.setDistanceThreshold (m_distance_threshold);

  Matrix <UInt32> accumulator_copy2;

  while (true) {
    max = accumulator_copy.max (theta, rho);

    if (accumulator_copy2 == accumulator_copy || max == 0)
      break;

    accumulator_copy2 = accumulator_copy;

    std::cout << "max: " << max << std::endl;

    if (clusters.size () == 0) {
      std::cout << "rho->" << m_rho_steps[rho] << std::endl;
      std::cout << "theta->" << m_theta_steps[theta] << std::endl;
    }
    line = Line (m_rho_steps[rho], m_theta_steps[theta]);

    inliers.setLine (line);

    inliers.compute (cloud_copy, indices);

    extract.setIndices (indices);
    extract.setNegative (false);

    extract.compute (cloud_copy, line_cluster);


    extract.setNegative (true);

    extract.compute (cloud_copy, cloud_tmp);

    cloud_copy = cloud_tmp;

    ExtractIndices < Point2D <T> > extract2;
    ExtractEuclideanClusters < Point2D <T> > euclidean;
    std::vector <PointIndices> clusters_indices;
    PointCloudT < Point2D <T> > biggest_cloud;
    PointCloudT < Point2D <T> > extra_cloud;
    PointIndices biggest;
    int biggest_idx;
    Float64 max_distance = hypot (m_distance_threshold, m_distance_threshold);
    euclidean.setMaxDistance (max_distance*1.1);
    euclidean.setMinPointsPerCluster (m_min_points_per_cluster);

    euclidean.compute (line_cluster, clusters_indices);
    for (UInt32 i = 0; i < clusters_indices.size (); ++i) {
      if (clusters_indices[i].size () > biggest.size ()) {
        biggest = clusters_indices[i];
        biggest_idx = i;
      }
    }
    extract2.setNegative (false);
    extract2.setIndices (biggest);
    
    extract2.compute (line_cluster, biggest_cloud);

    extract2.setNegative (true);
    extract2.compute (line_cluster, extra_cloud);

    cloud_copy += extra_cloud;

    hough.remove (biggest_cloud, accumulator_copy, m_rho_steps, m_theta_steps);

    clusters.push_back (biggest_cloud);
    lines.push_back (line);
  }
}

template <typename T>
Float64
ExtractHoughClusters <T>::getDistanceThreshold () const
{
  return m_distance_threshold;
}

template <typename T>
void
ExtractHoughClusters <T>::setDistanceThreshold (Float64 distance)
{
  m_distance_threshold = distance;
}

template <typename T>
UInt32
ExtractHoughClusters <T>::getMinPointsPerCluster () const
{
  return m_min_points_per_cluster;
}

template <typename T>
void
ExtractHoughClusters <T>::setMinPointsPerCluster (UInt32 min)
{
  m_min_points_per_cluster = min;
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
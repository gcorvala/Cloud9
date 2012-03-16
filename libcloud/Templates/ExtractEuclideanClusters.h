#ifndef __EXTRACT_EUCLIDEAN_CLUSTERS_H__
#define __EXTRACT_EUCLIDEAN_CLUSTERS_H__

#include "PointCloudT.h"
#include "SearchT.h"
#include "LinearSearchT.h"

template <class PointT>
class ExtractEuclideanClusters {
  public:
    ExtractEuclideanClusters ();
    virtual ~ExtractEuclideanClusters ();

    void compute (const PointCloudT <PointT>& cloud, std::vector <PointCloudT <PointT> >& clusters) const;

    SearchT <PointT> getSearchMethod () const;
    void setSearchMethod (const SearchT <PointT>& search);

    Float64 getMaxDistance () const;
    void setMaxDistance (Float64 max_distance);

    UInt32 getMinPointsPerCluster () const;
    void setMinPointsPerCluster (UInt32 min_points_per_cluster);

    UInt32 getMaxPointsPerCluster () const;
    void setMaxPointsPerCluster (UInt32 max_points_per_cluster);

  protected:
    SearchT <PointT>* m_search;
    Float64 m_max_distance;
    UInt32 m_min_points_per_cluster;
    UInt32 m_max_points_per_cluster;
};

template <class PointT>
ExtractEuclideanClusters <PointT>::ExtractEuclideanClusters ()
  :m_search (new LinearSearchT <PointT> ())
  ,m_max_distance (15)
  ,m_min_points_per_cluster (15)
  ,m_max_points_per_cluster (100000)
{
}

template <class PointT>
ExtractEuclideanClusters <PointT>::~ExtractEuclideanClusters ()
{
  delete m_search;
}

template <class PointT>
void
ExtractEuclideanClusters <PointT>::compute (const PointCloudT <PointT>& cloud, std::vector <PointCloudT <PointT> >& clusters) const
{
  m_search->setInputCloud (cloud);

  std::vector <Boolean> processed (cloud.size (), false);

  PointIndices nn_indices;
  std::vector <Float64> nn_distances;

  for (UInt32 i = 0; i < cloud.size (); ++i) {
    if (processed[i]) {
      continue;
    }
    else {
      std::vector <UInt32> seed_queue;

      int sq_idx = 0;
      seed_queue.push_back (i);
      
      processed[i] = true;
      
      while (sq_idx < seed_queue.size ()) {
        if (!m_search->radiusSearch (cloud[seed_queue[sq_idx]], m_max_distance, nn_indices, nn_distances)) {
          ++sq_idx;
          continue;
        }
        
        for (UInt32 j = 1; j < nn_indices.size (); ++j) {
          if (processed[nn_indices[j]]) {
            continue;
          }
          else {
            processed[nn_indices[j]] = true;
            seed_queue.push_back (nn_indices[j]);
          }
        }
        ++sq_idx;
      }
      if (seed_queue.size () >= m_min_points_per_cluster && seed_queue.size () <= m_max_points_per_cluster) {
        PointCloudT <PointT> cluster;
        //cluster.resize (seed_queue.size ());
        for (UInt32 j = 0; j < seed_queue.size (); ++j) {
          //cluster[j] = cloud[seed_queue[j]];
          cluster.push_back (cloud[seed_queue[j]]);
        }
        
        clusters.push_back (cluster);
      }
    }
  }
}

template <class PointT>
SearchT <PointT>
ExtractEuclideanClusters <PointT>::getSearchMethod () const
{
  return *m_search;
}

template <class PointT>
void
ExtractEuclideanClusters <PointT>::setSearchMethod (const SearchT <PointT>& search)
{
  delete m_search;
  m_search = search.clone ();
}

template <class PointT>
Float64
ExtractEuclideanClusters <PointT>::getMaxDistance () const
{
  return m_max_distance;
}

template <class PointT>
void
ExtractEuclideanClusters <PointT>::setMaxDistance (Float64 max_distance)
{
  m_max_distance = max_distance;
}

template <class PointT>
UInt32
ExtractEuclideanClusters <PointT>::getMinPointsPerCluster () const
{
  return m_min_points_per_cluster;
}

template <class PointT>
void
ExtractEuclideanClusters <PointT>::setMinPointsPerCluster (UInt32 min_points_per_cluster)
{
  m_min_points_per_cluster = min_points_per_cluster;
}

template <class PointT>
UInt32
ExtractEuclideanClusters <PointT>::getMaxPointsPerCluster () const
{
  return m_max_points_per_cluster;
}

template <class PointT>
void
ExtractEuclideanClusters <PointT>::setMaxPointsPerCluster (UInt32 max_points_per_cluster)
{
  m_max_points_per_cluster = max_points_per_cluster;
}

#endif
#ifndef __EXTRACT_CLUSTERS_H__
#define __EXTRACT_CLUSTERS_H__

#include "PointCloudT.h"
#include "Types.h"

template <class PointT>
class ExtractClusters {
  public:
    ExtractClusters ();
    virtual ~ExtractClusters ();

    virtual void compute (const PointCloudT <PointT>& cloud, std::vector <PointIndices>& clusters) const = 0;
    
    void getClustersPoints (const PointCloudT <PointT>& cloud, const std::vector <PointIndices>& clusters_indices, std::vector < PointCloudT <PointT> >& clusters) const;
    //void compute (const PointCloudT <PointT>& cloud, std::vector < PointCloudT <PointT> >& clusters) const;

    void setInputIndices (const PointIndices& indices);
    PointIndices getInputIndices () const;

  protected:
    PointIndices m_input_indices;
};

template <class PointT>
ExtractClusters <PointT>::ExtractClusters ()
{
}

template <class PointT>
ExtractClusters <PointT>::~ExtractClusters ()
{
}

template <class PointT>
void
ExtractClusters <PointT>::getClustersPoints (const PointCloudT <PointT>& cloud, const std::vector <PointIndices>& clusters_indices, std::vector < PointCloudT <PointT> >& clusters) const
{
  std::vector <PointIndices>::const_iterator it;

  clusters.clear ();

  for (it = clusters_indices.begin (); it != clusters_indices.end (); ++it) {
    PointCloudT <PointT> cluster;
    PointIndices::const_iterator idx;

    for (idx = it->begin (); idx != it->end (); ++idx) {
      cluster.push_back (cloud[*idx]);
    }

    clusters.push_back (cluster);
  }
}


/*template <class PointT>
void
ExtractClusters <PointT>::compute (const PointCloudT <PointT>& cloud, std::vector < PointCloudT <PointT> >& clusters) const
{
  std::vector <PointIndices> clusters_indices;
  std::vector <PointIndices>::const_iterator it;

  clusters.clear ();

  compute (cloud, clusters_indices);

  for (it = clusters_indices.begin (); it != clusters_indices.end (); ++it) {
    PointCloudT <PointT> cluster;
    PointIndices::const_iterator idx;

    for (idx = it->begin (); idx != it->end (); ++idx) {
      cluster.push_back (cloud[*idx]);
    }

    clusters.push_back (cluster);
  }
}*/

template <class PointT>
void
ExtractClusters <PointT>::setInputIndices (const PointIndices& indices)
{
  m_input_indices = indices;
}

template <class PointT>
PointIndices
ExtractClusters <PointT>::getInputIndices () const
{
  return m_input_indices;
}

#endif
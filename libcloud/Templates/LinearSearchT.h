#ifndef __LINEAR_SEARCH_T_H__
#define __LINEAR_SEARCH_T_H__

#include "SearchT.h"

template <class PointT>
class LinearSearchT : public SearchT <PointT> {
  public:
    LinearSearchT ();
    virtual ~LinearSearchT ();

    UInt32 nearestKSearch (const PointT& p, UInt32 k, PointIndices& k_indices, std::vector <Float64>& k_sqr_distances) const;
    UInt32 radiusSearch (const PointT& p, Float64 radius, PointIndices& k_indices, std::vector <Float64>& k_sqr_distances) const;

    SearchT <PointT>* clone () const;
};

template <class PointT>
LinearSearchT <PointT>::LinearSearchT ()
{
}

template <class PointT>
LinearSearchT <PointT>::~LinearSearchT ()
{
}

template <class PointT>
UInt32
LinearSearchT <PointT>::nearestKSearch (const PointT& p, UInt32 k, PointIndices& k_indices, std::vector <Float64>& k_sqr_distances) const
{
  typename PointCloudT <PointT>::const_iterator it;

  k_indices.clear ();
  k_sqr_distances.clear ();

  if (k > 0) {
    for (it = SearchT <PointT>::m_cloud->begin (); it != SearchT <PointT>::m_cloud->end (); ++it) {
      Float64 norm2 = p.distanceTo (*it);
      norm2 *= norm2;
      if (k_indices.empty () && k_sqr_distances.empty ()) {
        k_indices.push_back (std::distance (SearchT <PointT>::m_cloud->begin (), it));
        k_sqr_distances.push_back (norm2);
      }
      else {
        std::vector <Float64>::iterator it2;
        it2 = k_sqr_distances.begin ();
        while (it2 != k_sqr_distances.end () && *it2 < norm2) {
          ++it2;
        }
        k_indices.insert (k_indices.begin () + std::distance (k_sqr_distances.begin (), it2), std::distance (SearchT <PointT>::m_cloud->begin (), it));
        k_sqr_distances.insert (it2, norm2);
        if (k_indices.size () > k) {
          k_indices.pop_back ();
          k_sqr_distances.pop_back ();
        }
      }
    }
  }

  return k_indices.size ();
}

template <class PointT>
UInt32
LinearSearchT <PointT>::radiusSearch (const PointT& p, Float64 radius, PointIndices& k_indices, std::vector <Float64>& k_sqr_distances) const
{
  typename PointCloudT <PointT>::const_iterator it;

  k_indices.clear ();
  k_sqr_distances.clear ();

  Float64 sqr_radius = radius*radius;

  for (it = SearchT <PointT>::m_cloud->begin (); it != SearchT <PointT>::m_cloud->end (); ++it) {
    Float64 norm2 = p.distanceTo (*it);
    norm2 *= norm2;
    if (norm2 <= sqr_radius) {
      if (k_indices.empty () && k_sqr_distances.empty ()) {
        k_indices.push_back (std::distance (SearchT <PointT>::m_cloud->begin (), it));
        k_sqr_distances.push_back (norm2);
      }
      else {
        std::vector <Float64>::iterator it2;
        it2 = k_sqr_distances.begin ();
        while (it2 != k_sqr_distances.end () && *it2 < norm2) {
          ++it2;
        }
        k_indices.insert (k_indices.begin () + std::distance (k_sqr_distances.begin (), it2), std::distance (SearchT <PointT>::m_cloud->begin (), it));
        k_sqr_distances.insert (it2, norm2);
      }
    }
  }

  return k_indices.size ();
}

template <class PointT>
SearchT <PointT>*
LinearSearchT <PointT>::clone () const
{
  LinearSearchT* clone = new LinearSearchT (*this);

  return clone;
}

#endif
#include "LinearSearch.h"

#include <iostream> // FIXME
#include "../Common/Vector.h"

LinearSearch::LinearSearch ()
{
}

LinearSearch::~LinearSearch ()
{
}

int
LinearSearch::nearestKSearch (const Point& p,
                              unsigned int k,
                              std::vector<unsigned int>& k_indices,
                              std::vector<float>& k_sqr_distances)
{
  PointCloud::const_iterator it;

  k_indices.clear ();
  k_sqr_distances.clear ();

  if (k > 0) {
    for (it = cloud->begin (); it != cloud->end (); ++it) {
      Vector v (*it, p);
      double norm2 = v.norm2 ();
      if (k_indices.empty () && k_sqr_distances.empty ()) {
        k_indices.push_back (std::distance (cloud->begin (), it));
        k_sqr_distances.push_back (norm2);
      }
      else {
        std::vector<float>::iterator it2;
        it2 = k_sqr_distances.begin ();
        while (it2 != k_sqr_distances.end () && *it2 < norm2) {
          ++it2;
        }
        k_indices.insert (k_indices.begin () + std::distance (k_sqr_distances.begin (), it2), std::distance (cloud->begin (), it));
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

int
LinearSearch::radiusSearch (const Point& p,
                            double radius,
                            std::vector<unsigned int>& k_indices,
                            std::vector<float>& k_squared_distances)
{
  PointCloud::const_iterator it;

  k_indices.clear ();
  k_squared_distances.clear ();

  double sqr_radius = radius * radius;

  for (it = cloud->begin (); it != cloud->end (); ++it) {
    Vector v (*it, p);
    double norm2 = v.norm2 ();
    if (norm2 <= sqr_radius) {
      k_indices.push_back (std::distance (cloud->begin (), it));
      k_squared_distances.push_back (norm2);
    }
  }

  return k_indices.size ();
}

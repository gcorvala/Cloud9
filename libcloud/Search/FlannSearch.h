#ifndef __FLANN_SEARCH_H__
#define __FLANN_SEARCH_H__

#include "Search.h"

#include <flann/flann.hpp>

class FlannSearch : public Search {
  public:
    FlannSearch ();
    virtual ~FlannSearch ();
    void setInputCloud (const PointCloud& _cloud);
    int nearestKSearch (const Point& p, unsigned int k, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances);
    int radiusSearch (const Point& p, double radius, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances);
  protected:
    flann::Index<flann::L2<float> > *index; // FIXME : L2 ?
};

#endif
#ifndef __LINEAR_SEARCH_H__
#define __LINEAR_SEARCH_H__

#include "Search.h"

class LinearSearch : public Search {
  public:
    LinearSearch ();
    virtual ~LinearSearch ();
    int nearestKSearch (const Point& p, unsigned int k, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances);
    int radiusSearch (const Point& p, double radius, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances);
};

#endif
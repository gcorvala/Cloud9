#ifndef __SEARCH_H__
#define __SEARCH_H__

#include "../Common/Point.h"
#include "../Common/PointCloud.h"

class Search {
  public:
    Search ();
    virtual ~Search ();
    void setInputCloud (const PointCloud& _cloud);
    virtual int nearestKSearch (const Point& p, unsigned int k, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances) = 0;
    virtual int radiusSearch (const Point& p, double radius, std::vector<unsigned int>& k_indices, std::vector<float>& k_squared_distances) = 0;
  protected:
    const PointCloud *cloud;
};

#endif
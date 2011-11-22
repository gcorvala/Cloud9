#ifndef __FEATURE_H__
#define __FEATURE_H__

#include "../Common/PointCloud.h"
#include "../Search/Search.h"

class Feature {
  public:
    Feature ();
    virtual ~Feature ();
    void setInputCloud (const PointCloud& _cloud);
    void setSearchMethod (Search& _search);
    void setKSearch (unsigned int _k);
    void setRadiusSearch (double _radius);
    virtual void compute (PointCloud& output) = 0;
  protected:
    const PointCloud *cloud;
    Search *search;
    unsigned int k;
    double radius;
};

#endif
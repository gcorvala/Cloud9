#ifndef __HOUGH_TRANSFORM_H__
#define __HOUGH_TRANSFORM_H__

#include "../Common/PointCloud3D.h"
#include "Accumulator2D.h"

class HoughTransform {
  public:
    typedef HoughTransform* ptr;
    typedef const HoughTransform* const_ptr;

    HoughTransform ();
    HoughTransform (const HoughTransform& hough);
    ~HoughTransform ();

    virtual HoughTransform::ptr copy () const = 0;

    virtual void setInput (const PointCloud3D& cloud);
    const PointCloud3D& getInput () const;

    virtual void run () = 0;

    const Accumulator& getAccumulator () const;
    
    void findMaxima (Float32 threshold, std::vector <Float32>& maxima_values, std::vector <Indices>& maxima_voter_ids);

  protected:
    virtual void getInliers (const PointCloud3D& cloud, const Indices& max, Indices& inliers) const = 0;

    Accumulator::ptr m_accumulator;
    PointCloud3D::const_ptr m_cloud;
    std::vector <UInt32> m_n_values;
    Point3D m_min;
};

#endif

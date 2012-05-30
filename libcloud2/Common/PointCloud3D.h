#ifndef __POINT_CLOUD_3D_H__
#define __POINT_CLOUD_3D_H__

#include "../Geometry/Point3D.h"
#include "../Geometry/BoundingBox3D.h"
#include <vector>

class PointCloud3D {
  public:
    typedef PointCloud3D* ptr;
    typedef const PointCloud3D* const_ptr;
    typedef std::vector<Point3D>::iterator iterator;
    typedef std::vector<Point3D>::const_iterator const_iterator;

    PointCloud3D ();

    iterator begin ();
    iterator end ();
    const_iterator begin () const;
    const_iterator end () const;

    UInt32 size () const;
    void reserve (UInt32 n);
    void resize (UInt32 n);

    bool empty ();

    const Point3D& operator[] (UInt32 n) const;
    Point3D& operator[] (UInt32 n);
    const Point3D& at (UInt32 n) const;
    Point3D& at (UInt32 n);

    PointCloud3D& operator+= (const Point3D& p);
    PointCloud3D& operator+= (const PointCloud3D& pc);

    void clear ();
    
    BoundingBox3D getBoundingBox () const;

  protected:
    std::vector<Point3D> m_points;
};

#endif

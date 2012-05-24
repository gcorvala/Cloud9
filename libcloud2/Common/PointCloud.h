#ifndef __POINT_CLOUD_H__
#define __POINT_CLOUD_H__

#include "../Geometry/Point.h"
#include <vector>

class PointCloud {
  public:
    typedef PointCloud* ptr;
    typedef const PointCloud* const_ptr;
    typedef std::vector<Point>::iterator iterator;
    typedef std::vector<Point>::const_iterator const_iterator;

    PointCloud ();

    iterator begin ();
    iterator end ();
    const_iterator begin () const;
    const_iterator end () const;

    UInt32 size () const;
    void reserve (UInt32 n);
    void resize (UInt32 n);

    bool empty ();

    const Point& operator[] (UInt32 n) const;
    Point& operator[] (UInt32 n);
    const Point& at (UInt32 n) const;
    Point& at (UInt32 n);

    PointCloud& operator+= (const Point& p);
    PointCloud& operator+= (const PointCloud& pc);

    void clear ();

  protected:
    std::vector<Point> m_points;
};

#endif

#ifndef __POINT_CLOUD_H__
#define __POINT_CLOUD_H__

#include "Point.h"
#include "Box.h"

#include <vector>

class PointCloud {
  public:
    typedef std::vector<Point>::iterator iterator;
    typedef std::vector<Point>::const_iterator const_iterator;

    PointCloud ();
    PointCloud (PointCloud& pc);
    PointCloud (const PointCloud& pc);
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
    const Point& front () const;
    Point& front ();
    const Point& back () const;
    Point& back ();
    void push_back (const Point& p);
    iterator insert (iterator position, const Point& p);
    void insert (iterator position, UInt32 n, const Point& p);
    iterator erase (iterator position);
    iterator erase (iterator first, iterator last);
    void clear ();

    // FIXME
    Point getMin () const;
    Point getMax () const;
    Box getBoundingBox () const;

  protected:
    std::vector<Point> points;
};

#endif

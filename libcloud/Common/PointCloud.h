#ifndef __POINT_CLOUD_H__
#define __POINT_CLOUD_H__

#include "Point.h"

#include <vector>
#include <cstring>

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
    size_t size () const;
    void reserve (size_t n);
    void resize (size_t n);
    bool empty ();
    const Point& operator[] (size_t n) const;
    Point& operator[] (size_t n);
    const Point& at (size_t n) const;
    Point& at (size_t n);
    const Point& front () const;
    Point& front ();
    const Point& back () const;
    Point& back ();
    void push_back (const Point& p);
    iterator insert (iterator position, const Point& p);
    void insert (iterator position, size_t n, const Point& p);
    iterator erase (iterator position);
    iterator erase (iterator first, iterator last);
    void clear ();

  protected:
    std::vector<Point> points;
};

#endif

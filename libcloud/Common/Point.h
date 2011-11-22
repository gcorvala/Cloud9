#ifndef __POINT_H__
#define __POINT_H__

class Point {
  public:
    Point ();
    Point (double _x, double _y, double _z);
    virtual ~Point ();
    void normalize ();
    double norm () const;
    double norm2 () const;
    Point operator+ (const Point& p) const;
    Point operator- (const Point& p) const;
    Point operator* (double s) const;
    Point operator/ (double s) const;
    Point operator= (const Point& p);
    Point operator+= (const Point& p);
    Point operator-= (const Point& p);
    Point operator*= (double s);
    Point operator/= (double s);
    bool operator== (const Point& p) const;
    bool operator!= (const Point& p) const;
    double x;
    double y;
    double z;
};

#endif
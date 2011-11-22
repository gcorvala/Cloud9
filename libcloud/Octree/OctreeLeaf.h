#ifndef __OCTREE_LEAF_H__
#define __OCTREE_LEAF_H__

#include "OctreeNode.h"
#include "../Common/Point.h"
#include <vector>

class OctreeLeaf : public OctreeNode {
  public:
    OctreeLeaf ();
    virtual ~OctreeLeaf ();
    virtual void setData (const Point& p) = 0;
    virtual void getData (Point& p) const = 0;
    virtual void getData (std::vector<Point>& v) const = 0;
    virtual void reset () = 0;
};

class OctreeLeafPoint : public OctreeLeaf {
  public:
    OctreeLeafPoint ();
    virtual ~OctreeLeafPoint ();
    virtual void setData (const Point& p);
    virtual void getData (Point& p) const;
    virtual void getData (std::vector<Point>& v) const;
    virtual void reset ();
    bool isLeaf () const;
  protected:
    Point data;
};

class OctreeLeafPointVector : public OctreeLeaf {
  
};

class OctreeLeafEmpty : public OctreeLeaf {
  
};

#endif
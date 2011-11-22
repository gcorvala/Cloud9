#ifndef __KDTREE_NODE_H__
#define __KDTREE_NODE_H__

#include "../Common/Point.h"
#include <vector>

class KdtreeNode {
  public:
    KdtreeNode ();
    KdtreeNode (std::vector<Point>& points, unsigned int depth = 0);
    virtual ~KdtreeNode ();
    bool hasChild () const;
    bool hasLeftChild () const;
    bool hasRightChild () const;
    bool getLeftChild (KdtreeNode& child) const;
    bool getRightChild (KdtreeNode& child) const; 
    const KdtreeNode& getLeftChild () const;
    const KdtreeNode& getRightChild () const;
    const Point& getMedian () const;
    void setLeftChild (const KdtreeNode& left);
    void setRightChild (const KdtreeNode& right);
    void setMedian (const Point& p);
  protected:
    Point data;
    unsigned int depth;
    const KdtreeNode* left;
    const KdtreeNode* right;
};

#endif
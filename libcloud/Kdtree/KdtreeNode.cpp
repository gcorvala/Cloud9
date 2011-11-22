#include "KdtreeNode.h"

#include <math.h>
#include <algorithm>
#include <assert.h> // FIXME
#include "../Common/Utils.h"

#include <iostream> // FIXME

KdtreeNode::KdtreeNode ()
{
}

KdtreeNode::KdtreeNode (std::vector<Point>& points, unsigned int depth)
  : left(NULL), right(NULL)
{
  if (points.size () == 1)
  {
    data = points[0];
  }
  else {
    std::vector<Point>::iterator median_it;
    std::vector<Point> before;
    std::vector<Point> after;
    // FIXME : 3 is the dimension ?
    unsigned int axis = depth % 3;
    switch (axis) {
      case 0:
        sort (points.begin (), points.end (), comparePointsByXAxis);
        break;
      case 1:
        sort (points.begin (), points.end (), comparePointsByYAxis);
        break;
      case 2:
        sort (points.begin (), points.end (), comparePointsByZAxis);
        break;
    }
    // FIXME : Building a static k-d tree from n points takes O(n log 2 n)
    // time if an O(n log n) sort is used to compute the median at each level.
    // The complexity is O(n log n) if a linear median-finding algorithm such
    // as the one described in Cormen et al.[5] is used.
    median_it = points.begin () + ceil (points.size () / 2) - 1;
    data = *median_it;

    before.resize (std::distance (points.begin (), median_it));
    after.resize (std::distance (median_it, points.end ()) - 1);

    assert (points.size () == (before.size () + after.size () + 1));

    copy (points.begin (), median_it++, before.begin ());
    copy (median_it, points.end (), after.begin ());

    if (!before.empty ()) {
      left = new KdtreeNode (before, depth + 1);
    }
    if (!after.empty ()) {
      right = new KdtreeNode (after, depth + 1);
    }
  }
}

KdtreeNode::~KdtreeNode ()
{
  if (left) {
    delete left;
  }
  if (right) {
    delete right;
  }
}

bool
KdtreeNode::getLeftChild (KdtreeNode& child) const
{
  bool result;

  if (!left) {
    result = false;
  }
  else {
    child = *left;
    result = true;
  }

  return result;
}

bool
KdtreeNode::getRightChild (KdtreeNode& child) const
{
  bool result;

  if (!right) {
    result = false;
  }
  else {
    child = *right;
    result = true;
  }

  return result;
}


void
KdtreeNode::setLeftChild (const KdtreeNode& _left)
{
  left = &_left;
}

void
KdtreeNode::setRightChild (const KdtreeNode& _right)
{
  right = &_right;
}

void
KdtreeNode::setMedian (const Point& p)
{
  data = p;
}

const KdtreeNode&
KdtreeNode::getLeftChild () const
{
  return *left;
}

const KdtreeNode&
KdtreeNode::getRightChild () const
{
  return *right;
}

const Point&
KdtreeNode::getMedian () const
{
  return data;
}

#include "Octree.h"

#include <math.h>
#include "../Common/Vector.h"

Octree::Octree (const Float64 resolution)
  :m_resolution(resolution)
  ,m_bounding_box(Point (0, 0, 0), Point (resolution, resolution, resolution))
  ,branch_count(0)
  ,leaf_count(0)
  ,object_count(0)
  ,root(new OctreeBranch ())
  ,depth(0)
{
}

Octree::~Octree()
{
}

unsigned int
Octree::getDepth () const
{
  return depth;
}

void
Octree::add (const Point& point)
{
  OctreeKey key;

  adoptBoundingBoxToPoint (point);
  genOctreeKeyForPoint (point, key);
  add (key, point);
}

void
Octree::add (const PointCloud& cloud)
{
  PointCloud::const_iterator it;
  OctreeKey key;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    add (*it);
  }
}

void
Octree::add (const OctreeKey& k, const Point& p)
{
  OctreeLeaf * leaf = getLeaf (k);

  if (leaf) {
    leaf->setData (p);
    object_count++;
  }
}

OctreeLeaf *
Octree::getLeaf (const OctreeKey& k)
{
  return getLeafRecursive (k, 1 << depth, *root);
}

OctreeLeaf *
Octree::getLeafRecursive (const OctreeKey& k, const unsigned int mask, OctreeBranch& branch)
{
  unsigned char idx;
  OctreeLeaf* result = NULL;

  idx = ((!!(k.x & mask)) << 2) | ((!!(k.y & mask)) << 1) | (!!(k.z & mask));

  if (mask > 1) {
    OctreeBranch * child;
    if (!branch.hasChild (idx)) {
      child = new OctreeBranch ();
      branch.setBranchChild (idx, *child);
      branch_count++;
    }
    else {
      // FIXME: const casted !!!!
      child = (OctreeBranch *) &branch.getBranchChild (idx);
    }
    result = getLeafRecursive (k, mask >> 1, *child);
  }
  else {
    OctreeLeaf * child;
    if (!branch.hasChild (idx)) {
      child = new OctreeLeafPoint ();
      branch.setBranchChild (idx, *child);
      leaf_count++;
    }
    else {
      Point p;
      child = (OctreeLeaf *) &branch.getBranchChild (idx);
      child->getData (p);
    }
    result = child;
  }
  return result;
}

unsigned int
Octree::getLeafCount () const
{
  return leaf_count;
}

unsigned int
Octree::getBranchCount () const
{
  return branch_count;
}

unsigned int
Octree::getObjectCount () const
{
  return object_count;
}

const OctreeNode&
Octree::getRootNode () const
{
  return *root;
}

void
Octree::adoptBoundingBoxToPoint (const Point& p)
{
  if (leaf_count == 0) {
    Vector half_resolution (m_resolution/2, m_resolution/2, m_resolution/2);
    m_bounding_box.setMin (Vector (p)-half_resolution);
    m_bounding_box.setMax (Vector (p)+half_resolution);
  }
  else {
    while (true) {
      Point min = m_bounding_box.getMin ();
      Point max = m_bounding_box.getMax ();

      bool min_x_violation = p.x < min.x;
      bool min_y_violation = p.y < min.y;
      bool min_z_violation = p.z < min.z;
      bool max_x_violation = p.x >= max.x;
      bool max_y_violation = p.y >= max.y;
      bool max_z_violation = p.z >= max.z;
      
      if (min_x_violation || min_y_violation || min_z_violation
        || max_x_violation || max_y_violation || max_z_violation) {
        OctreeBranch* new_root;
        unsigned int idx;
        double side_length;

        new_root = new OctreeBranch ();
        idx = (max_x_violation << 2) | (max_y_violation << 1) | max_z_violation;
        new_root->setBranchChild (idx, *root);
        root = new_root;

        side_length = m_bounding_box.getWidth ();
        if (max_x_violation) {
          m_bounding_box.setMax (Vector (m_bounding_box.getMax ())+Vector(side_length, 0, 0));
        }
        else {
          m_bounding_box.setMin (Vector (m_bounding_box.getMin ())-Vector(side_length, 0, 0));
        }

        if (max_y_violation) {
          m_bounding_box.setMax (Vector (m_bounding_box.getMax ())+Vector(0, side_length, 0));
        }
        else {
          m_bounding_box.setMin (Vector (m_bounding_box.getMin ())-Vector(0, side_length, 0));
        }

        if (max_z_violation) {
          m_bounding_box.setMax (Vector (m_bounding_box.getMax ())+Vector(0, 0, side_length));
        }
        else {
          m_bounding_box.setMin (Vector (m_bounding_box.getMin ())-Vector(0, 0, side_length));
        }

        branch_count++;
        depth++;
      }
      else {
        break;
      }
    }
  }
}

void
Octree::genOctreeKeyForPoint (const Point& p, OctreeKey& k) const
{
  Vector diff (Vector (p)-Vector (m_bounding_box.getMin ()));
  diff /= m_resolution;
  k.x = floor (diff.x);
  k.y = floor (diff.y);
  k.z = floor (diff.z);
}
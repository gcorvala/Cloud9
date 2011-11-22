#include "Octree.h"

#include <iostream> // FIXME
#include <assert.h> // FIXME
#include <math.h>

Octree::Octree (const double _resolution)
  : cloud(NULL), resolution(_resolution),
    min_x(0.0), min_y(0.0), min_z(0.0),
    max_x(_resolution), max_y(_resolution), max_z(_resolution),
    branch_count(0), leaf_count(0), object_count(0),
    root(new OctreeBranch ()),
    depth(0)
{
}

Octree::~Octree()
{
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

void
Octree::setInputCloud (const PointCloud& _cloud)
{
  assert (leaf_count == 0);

  if (cloud != &_cloud) {
    cloud = &_cloud;
  }
}

void
Octree::addPointsFromCloud ()
{
  unsigned int i;

  assert (leaf_count == 0);

  for (i = 0; i < cloud->size (); ++i) {
    addPointIdx (i);
  }

  std::cout << "min x : " << min_x << std::endl; 
  std::cout << "min y : " << min_y << std::endl; 
  std::cout << "min z : " << min_z << std::endl; 
  std::cout << "max x : " << max_x << std::endl; 
  std::cout << "max y : " << max_y << std::endl; 
  std::cout << "max z : " << max_z << std::endl; 
}

unsigned int
Octree::getDepth () const
{
  return depth;
}

const OctreeNode&
Octree::getRootNode () const
{
  return *root;
}

void
Octree::addPointIdx (const unsigned int idx)
{
  OctreeKey key;

  assert (idx < cloud->size ());

  const Point& point = cloud->at(idx);

  adoptBoundingBoxToPoint (point);

  genOctreeKeyForPoint (point, key);

  add (key, point);
}

void
Octree::adoptBoundingBoxToPoint (const Point& p)
{
  if (leaf_count == 0) {
    min_x = p.x - (resolution / 2);
    min_y = p.y - (resolution / 2);
    min_z = p.z - (resolution / 2);
    max_x = p.x + (resolution / 2);
    max_y = p.y + (resolution / 2);
    max_z = p.z + (resolution / 2);
  }
  else {
    while (true) {
      bool min_x_violation = p.x < min_x;
      bool min_y_violation = p.y < min_y;
      bool min_z_violation = p.z < min_z;
      bool max_x_violation = p.x >= max_x;
      bool max_y_violation = p.y >= max_y;
      bool max_z_violation = p.z >= max_z;
      if (min_x_violation || min_y_violation || min_z_violation
        || max_x_violation || max_y_violation || max_z_violation) {
        OctreeBranch* new_root;
        unsigned int idx;
        double side_length;

        new_root = new OctreeBranch ();
        idx = (max_x_violation << 2) | (max_y_violation << 1) | max_z_violation;
        new_root->setBranchChild (idx, *root);
        root = new_root;

        side_length = max_x - min_x;
        if (max_x_violation) {
          max_x += side_length;
        }
        else {
          min_x -= side_length;
        }

        if (max_y_violation) {
          max_y += side_length;
        }
        else {
          min_y -= side_length;
        }

        if (max_z_violation) {
          max_z += side_length;
        }
        else {
          min_z -= side_length;
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
  k.x = floor ((p.x - min_x) / resolution);
  k.y = floor ((p.y - min_y) / resolution);
  k.z = floor ((p.z - min_z) / resolution);
}

void
Octree::test ()
{
}

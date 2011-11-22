#include "OctreeNode.h"

#include <string.h>

OctreeNode::OctreeNode ()
{
}

OctreeNode::~OctreeNode ()
{
}

bool
OctreeNode::isBranch () const
{
  return false;
}

bool
OctreeNode::isLeaf () const
{
  return false;
}
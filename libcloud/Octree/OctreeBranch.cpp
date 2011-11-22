#include "OctreeBranch.h"

#include <string>
#include <iostream> // FIXME
#include <string.h>

OctreeBranch::OctreeBranch ()
{
  memset (children, 0, sizeof (children));
}

OctreeBranch::~OctreeBranch ()
{
}

void
OctreeBranch::setBranchChild (const unsigned char idx, const OctreeNode& child)
{
  children[idx] = &child;
}

const OctreeNode&
OctreeBranch::getBranchChild (const unsigned char idx) const
{
  return *children[idx];
}

bool
OctreeBranch::hasChild (const unsigned char idx) const
{
  return (children[idx] != 0);
}

bool
OctreeBranch::isBranch () const
{
  return true;
}

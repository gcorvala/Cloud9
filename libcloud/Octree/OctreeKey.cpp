#include "OctreeKey.h"

OctreeKey::OctreeKey ()
  : x(0), y(0), z(0)
{
}

OctreeKey::~OctreeKey ()
{
}

bool
OctreeKey::operator== (const OctreeKey& k) const
{
  return ((k.x == x) && (k.y == y) && k.z == z);
}
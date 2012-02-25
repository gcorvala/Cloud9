#include "OctreeIterator.h"

#if 0
#include <iostream> // FIXME

OctreeIterator::OctreeIterator (const Octree& o)
  : octree(&o), current(&octree->getRootNode ()), current_idx(0),
    current_depth(0)
{
  stack.reserve (octree->getDepth ());
}

OctreeIterator::~OctreeIterator ()
{
}

const OctreeKey&
OctreeIterator::getCurrentOctreeKey () const
{
  return current_key;
}

unsigned int
OctreeIterator::getCurrentOctreeDepth () const
{
  return current_depth;
}

const OctreeNode&
OctreeIterator::getCurrentOctreeNode () const
{
  return *current;
}

const OctreeNode*
OctreeIterator::operator* () const
{
  return current;
}

bool
OctreeIterator::operator== (const OctreeIterator& it) const
{
  return ((octree == it.octree) && (current == it.current));
}

bool
OctreeIterator::operator!= (const OctreeIterator& it) const
{
  return ((octree != it.octree) || (current != it.current));
}

//void skipChildVoxels ();

OctreeIterator&
OctreeIterator::operator++ ()
{
/*  std::pair<OctreeNode const*, unsigned char> entry;

  if (current) {
    if (current->isBranch ()) {
      unsigned char index;
      const OctreeBranch *branch = (const OctreeBranch*) current;
      for (index = 0; index < 8; ++index) {
        if (branch->hasChild (index)) {
          entry.first = current;
          entry.second = index;
          stack.push_back (entry);
          current = &branch->getBranchChild (index);
          break;
        }
      }
      if (index == 8) {
        entry = stack.back ();
        stack.pop_back ();
        current = entry.first;
        index = entry.second;
      }
    }
  }
  return *this;*/
  // FIXME : rewrite ?

  if (current) {
    bool bTreeUp = false;
    const OctreeNode* itNode = NULL;

    if (current->isBranch ()) {
      std::cout << "1" << std::endl;
      const OctreeBranch* current_branch = (const OctreeBranch*) current;
      while ((current_idx < 8) && !(itNode = &current_branch->getBranchChild (current_idx))) {
        current_idx++;
      }
      if (current_idx == 8) {
        bTreeUp = true;
      }
    }
    else {
      std::cout << "2" << std::endl;
      bTreeUp = true;
    }
    if (bTreeUp) {
      std::cout << "3" << std::endl;
      if (stack.size () > 0) {
        std::cout << "ok1" << std::endl;
        std::pair<OctreeNode const*, unsigned char>& stackEntry = stack.back ();
        stack.pop_back ();
        std::cout << "ok2" << std::endl;
        current = stackEntry.first;
        current_idx = stackEntry.second;
        current_key.x = current_key.x >> 1;
        current_key.y = current_key.y >> 1;
        current_key.z = current_key.z >> 1;
        current_depth--;
      }
      else {
        current = NULL;
      }
    }
    else {
      std::cout << "4" << std::endl;
      std::pair<OctreeNode const*, unsigned char> newStackEntry;
      newStackEntry.first = current;
      newStackEntry.second = current_idx + 1;
      stack.push_back (newStackEntry);
      current_key.x = (current_key.x << 1) | (!!(current_idx & (1 << 2)));
      current_key.y = (current_key.y << 1) | (!!(current_idx & (1 << 1)));
      current_key.z = (current_key.z << 1) | (!!(current_idx & (1 << 0)));
      current_depth++;
      current_idx = 0;
      current = itNode;
    }
  }

  if (current == NULL) {
    std::cout << "NULL" << std::endl;
  }

  return *this;
}

OctreeIterator
OctreeIterator::operator++ (int)
{
  OctreeIterator tmp = *this;
  ++*this;
  return tmp;
}

#else

#endif
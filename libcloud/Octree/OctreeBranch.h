#ifndef __OCTREE_BRANCH_H__
#define __OCTREE_BRANCH_H__

#include "OctreeNode.h"

class OctreeBranch : public OctreeNode {
  public:
    OctreeBranch ();
    virtual ~OctreeBranch ();
    void setBranchChild (const unsigned char idx, const OctreeNode& child);
    const OctreeNode& getBranchChild (const unsigned char idx) const;
    bool hasChild (const unsigned char idx) const;
    bool isBranch () const;
  protected:
    const OctreeNode * children[8];
};

#endif
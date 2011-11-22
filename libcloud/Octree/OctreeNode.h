#ifndef __OCTREE_NODE_H__
#define __OCTREE_NODE_H__

class OctreeNode {
  public:
    OctreeNode ();
    virtual ~OctreeNode ();
    virtual bool isBranch () const;
    virtual bool isLeaf () const;
};

#endif
#ifndef __OCTREE_NODE_H__
#define __OCTREE_NODE_H__

class OctreeNode {
  public:
    typedef OctreeNode* ptr;
    typedef const OctreeNode* const_ptr;

    OctreeNode ();
    virtual ~OctreeNode ();
    virtual bool isBranch () const;
    virtual bool isLeaf () const;
};

#endif
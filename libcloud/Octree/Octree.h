#ifndef __OCTREE_H__
#define __OCTREE_H__

#include "OctreeBranch.h"
#include "OctreeNode.h"
#include "OctreeKey.h"
#include "OctreeLeaf.h"
#include "OctreeIterator.h"
#include "../Common/Box.h"
#include "../Common/Point.h"
#include "../Common/PointCloud.h"
#include "../Common/Utils.h"

class OctreeIterator; // FIXME

class Octree {
    friend class OctreeIterator;
  public:
    typedef OctreeIterator iterator;
    typedef const OctreeIterator const_iterator;
    typedef Octree* ptr;
    typedef const Octree* const_ptr;

    Octree (const Float64 resolution);
    virtual ~Octree ();

    UInt32 getDepth () const;

    Float64 getResolution () const;
    void setResolution (Float64 resolution);

    void setMaxDepth (UInt32 depth);

    void add (const Point& point);
    void add (const PointCloud& cloud);

    bool existLeaf (UInt32 x_idx, UInt32 y_idx, UInt32 z_idx) const;

    UInt32 getLeafCount () const;
    UInt32 getBranchCount () const;
    UInt32 getObjectCount () const;

    iterator begin ();
    iterator end ();
    const_iterator begin () const;
    const_iterator end () const;
    
  protected:
    const OctreeNode& getRootNode () const; // FIXME : protected ?
    void add (const OctreeKey& k, const Point& p);
    bool get (const OctreeKey& k, Point& p) const;
    bool existLeaf (const OctreeKey& k) const;
    void removeLeaf (const OctreeKey& k);
    OctreeLeaf::ptr getLeaf (const OctreeKey& k);
    OctreeLeaf::ptr getLeafRecursive (const OctreeKey& k, const unsigned int depth, OctreeBranch& branch);
    void adoptBoundingBoxToPoint (const Point& p);
    void genOctreeKeyForPoint (const Point& p, OctreeKey& k) const;
  protected:
    Float64 m_resolution;
    Box m_bounding_box;
    UInt32 branch_count;
    UInt32 leaf_count;
    UInt32 object_count;

    OctreeBranch::ptr root;

    UInt32 depth;
};

#endif

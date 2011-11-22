#ifndef __OCTREE_H__
#define __OCTREE_H__

#include "OctreeBranch.h"
#include "OctreeNode.h"
#include "OctreeKey.h"
#include "OctreeLeaf.h"
#include "OctreeIterator.h"
#include "../Common/Point.h"
#include "../Common/PointCloud.h"
#include "../Common/Utils.h"

class OctreeIterator; // FIXME

class Octree {
    friend class OctreeIterator;
  public:
    typedef OctreeIterator iterator;
    typedef const OctreeIterator const_iterator;

    Octree (const double _resolution);
    virtual ~Octree ();
    void setDepth (unsigned int _depth);
    void add (unsigned int x_idx, unsigned int y_idx, unsigned int z_idx, Point& p);
    bool get (unsigned int x_idx, unsigned int y_idx, unsigned int z_idx, Point& p) const;
    bool existLeaf (unsigned int x_idx, unsigned int y_idx, unsigned int z_idx) const;
    void removeLeaf (unsigned int x_idx, unsigned int y_idx, unsigned int z_idx);
    unsigned int getLeafCount () const;
    unsigned int getBranchCount () const;
    void deleteTree ();
    void setInputCloud (const PointCloud& _cloud);
    void addPointsFromCloud ();
    // getIndices
    // getInputCloud
    // setResolution
    // getResolution
    // addPointToCloud
    // isVoxelOccupiedAtPoint
    
  protected:
    unsigned int getDepth () const; // FIXME : protected ?
    const OctreeNode& getRootNode () const; // FIXME : protected ?
    void add (const OctreeKey& k, const Point& p);
    bool get (const OctreeKey& k, Point& p) const;
    bool existLeaf (const OctreeKey& k) const;
    void removeLeaf (const OctreeKey& k);
    OctreeLeaf * getLeaf (const OctreeKey& k);
    OctreeLeaf * getLeafRecursive (const OctreeKey& k, const unsigned int depth, OctreeBranch& branch);
    unsigned int getObjectCount () const;
    void addPointIdx (const unsigned int idx);
    void adoptBoundingBoxToPoint (const Point& p);
    void genOctreeKeyForPoint (const Point& p, OctreeKey& k) const;
    void test ();
  protected:
    const PointCloud * cloud;
    double resolution;
    double min_x;
    double min_y;
    double min_z;
    double max_x;
    double max_y;
    double max_z;
    unsigned int branch_count;
    unsigned int leaf_count;
    unsigned int object_count;

    OctreeBranch* root;
    class leaf;

    unsigned int depth;
};

#endif

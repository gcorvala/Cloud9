#ifndef __KDTREE_H__
#define __KDTREE_H__

#include "KdtreeNode.h"
#include "../Common/PointCloud.h"
#include <vector>

// FIXME : use FLANN ?

class Kdtree {
  public:
    Kdtree ();
    virtual ~Kdtree ();
    void setInputCloud (const PointCloud& _cloud);
    void addPointsFromCloud ();
    const Point& nearestSearch (unsigned int index) const;
    unsigned int nearestKSearch (unsigned int index, unsigned int k, std::vector<unsigned int>& indices, std::vector<double>& distances);
  protected:
    const PointCloud* cloud;
    KdtreeNode* root;
};
/*
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
*/
#endif
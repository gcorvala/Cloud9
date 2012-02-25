#ifndef __OCTREE_ITERATOR_H__
#define __OCTREE_ITERATOR_H__

#include "Octree.h"
#include "OctreeKey.h"
#include "OctreeNode.h"
#include <iterator>
#include <vector>

class Octree; // FIXME : cross dep ?

class OctreeIterator : public std::iterator<std::forward_iterator_tag,
                                            const OctreeNode,
                                            void,
                                            const OctreeNode*,
                                            const OctreeNode&> {
  public:
    explicit OctreeIterator (const Octree& o);
    virtual ~OctreeIterator ();
    const OctreeKey& getCurrentOctreeKey () const;
    unsigned int getCurrentOctreeDepth () const;
    const OctreeNode& getCurrentOctreeNode () const;
    const OctreeNode* operator* () const;
    bool operator== (const OctreeIterator& it) const;
    bool operator!= (const OctreeIterator& it) const;
    void skipChildVoxels ();
    OctreeIterator& operator++ ();
    OctreeIterator operator++ (int);
  protected:
    const Octree* octree;
    const OctreeNode* current;
    unsigned char current_idx;
    unsigned int current_depth;
    OctreeKey current_key;
    std::vector<std::pair<OctreeNode const*, unsigned char> > stack;
    //std::vector<unsigned char> stack;
};

#endif

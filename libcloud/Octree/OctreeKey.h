#ifndef __OCTREE_KEY_H__
#define __OCTREE_KEY_H__

class OctreeKey {
  public:
    OctreeKey ();
    virtual ~OctreeKey ();
    bool operator== (const OctreeKey& k) const;
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

#endif
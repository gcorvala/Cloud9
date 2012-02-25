#ifndef __OCTREE_ACTOR_H__
#define __OCTREE_ACTOR_H__

#include "Actor.h"
#include <libcloud/Octree/Octree.h>

class OctreeActor : public Actor {
  public:
    OctreeActor (const Octree& octree);
    virtual ~OctreeActor ();
    void draw () const;
};

#endif

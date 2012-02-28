#ifndef __PLANE_ACTOR_H__
#define __PLANE_ACTOR_H__

#include "Actor.h"
#include <libcloud/Common/Plane.h>
#include <libcloud/Common/Point.h>

class PlaneActor : public Actor {
  public:
    PlaneActor (const Plane& plane);
    virtual ~PlaneActor ();
    void draw () const;
  private:
    Point m_p1;
    Point m_p2;
    Point m_p3;
    Point m_p4;
};

#endif

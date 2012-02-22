#ifndef __BOX_ACTOR_H__
#define __BOX_ACTOR_H__

#include "Actor.h"
#include <libcloud/Common/Point.h>

class BoxActor : public Actor {
  public:
    BoxActor (const Point& min, const Point& max);
    virtual ~BoxActor ();
    void draw () const;
  private:
    Point m_min;
    Point m_max;
};

#endif

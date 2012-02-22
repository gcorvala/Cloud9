#ifndef __AXIS_ACTOR_H__
#define __AXIS_ACTOR_H__

#include "Actor.h"
#include <libcloud/Common/Types.h>

class AxisActor : public Actor {
  public:
    AxisActor ();
    virtual ~AxisActor ();
    void draw () const;
  private:
    UInt32 size;
};

#endif

#ifndef __LINE_ACTOR_H__
#define __LINE_ACTOR_H__

#include "Actor.h"
#include <libcloud/Common/Point.h>

class LineActor : public Actor {
  public:
    LineActor (const Point& start, const Point& end);
    virtual ~LineActor ();
    void draw () const;
  private:
    Point m_start;
    Point m_end;
};

#endif

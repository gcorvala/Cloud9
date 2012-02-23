#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <vector>

class Actor {
  public:
    Actor ();
    virtual ~Actor ();
    virtual void draw () const;
  protected:
    std::vector<Actor*> children;
};

#endif

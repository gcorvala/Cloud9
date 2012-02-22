#ifndef __ACTOR_H__
#define __ACTOR_H__

class Actor {
  public:
    Actor ();
    virtual ~Actor ();
    virtual void draw () const = 0;
};

#endif

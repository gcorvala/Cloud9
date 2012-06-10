#ifndef __TIMER_H__
#define __TIMER_H__

#include "Types.h"
#include <time.h>

class Timer {
  public:
    Timer ();
    virtual ~Timer ();

    void restart ();

    Float32 getElapsed () const;

  protected:
    clock_t m_start_time;
};

#endif
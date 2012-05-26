#ifndef __INTERVAL_H__
#define __INTERVAL_H__

#include "Types.h"

class Interval {
  public:
    Interval (Float32 min, Float32 max);
    virtual ~Interval ();

    Float32 getMin () const;
    void setMin (Float32 min);

    Float32 getMax () const;
    void setMax (Float32 max);

    Float32 getLength () const;
    Float32 getCenter () const;

    Boolean contains (Float32 value) const;

  protected:
    Float32 m_min;
    Float32 m_max;
};

#endif
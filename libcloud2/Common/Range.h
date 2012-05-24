#ifndef __RANGE_H__
#define __RANGE_H__

#include "Types.h"

class Range {
  public:
    Range (Float32 min, Float32 max, Float32 step);
    virtual ~Range ();

    Float32 getMin () const;
    void setMin (Float32 min);

    Float32 getMax () const;
    void setMax (Float32 max);

    Float32 getStep () const;
    void setStep (Float32 step);

    UInt32 getSteps () const;
    UInt32 getValueIndex (Float32 value) const;

  protected:
    Float32 m_min;
    Float32 m_max;
    Float32 m_step;
};

#endif
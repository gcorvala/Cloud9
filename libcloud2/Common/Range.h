#ifndef __RANGE_H__
#define __RANGE_H__

#include "Types.h"
#include "Interval.h"

// Range type : [min;max[
class Range {
  public:
    typedef Range* ptr;
    typedef const Range* const_ptr;

    Range (Float32 min, Float32 max, UInt32 steps);
    virtual ~Range ();

    Float32 getMin () const;
    void setMin (Float32 min);

    Float32 getMax () const;
    void setMax (Float32 max);

    UInt32 getSteps () const;
    void setSteps (UInt32 steps);

    Float32 getStep () const;

    UInt32 getValueIndex (Float32 value) const;

    Boolean contains (Float32 value) const;

    Interval operator[] (UInt32 index) const; 

  protected:
    Float32 m_min;
    Float32 m_max;
    UInt32 m_steps;
};

#endif
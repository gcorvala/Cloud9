#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__

#include "../Common/Types.h"
#include "../Common/Range.h"
#include "../Common/ModelCoefficients.h"
#include <vector>

class Accumulator {
  public:
    typedef Accumulator* ptr;
    typedef const Accumulator* const_ptr;

    Accumulator ();
    virtual ~Accumulator ();

    virtual Accumulator& operator= (const Accumulator& accumulator) = 0;
    virtual Accumulator& operator-= (const Accumulator& accumulator) = 0;

    virtual Accumulator::ptr copy () const = 0;

    UInt32 getDimension () const;
    std::vector <UInt32> getDimensions () const;

    const std::vector <Range>& getRanges () const;
    
    virtual UInt32 getValue (const Indices& parameters) const = 0;

    virtual void vote (const ModelCoefficients& coeffs) = 0;

    virtual Indices getMaxValue () const = 0;

    virtual void reset () = 0;

  protected:
    virtual void alloc () = 0;
    virtual void free () = 0;

    std::vector <Range> m_ranges;
};

#endif
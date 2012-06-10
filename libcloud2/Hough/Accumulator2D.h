#ifndef __ACCUMULATOR_2D_H__
#define __ACCUMULATOR_2D_H__

#include "Accumulator.h"

class Accumulator2D : public Accumulator {
  public:
    Accumulator2D (const std::vector <Range>& ranges);
    Accumulator2D (const Range& r1, const Range& r2);
    Accumulator2D (const Accumulator2D& accumulator);
    virtual ~Accumulator2D ();

    Accumulator& operator= (const Accumulator& accumulator);
    Accumulator2D& operator= (const Accumulator2D& accumulator);
    Accumulator& operator-= (const Accumulator& accumulator);
    Accumulator2D& operator-= (const Accumulator2D& accumulator);

    UInt32& operator() (UInt32 i, UInt32 j);
    const UInt32& operator() (UInt32 i, UInt32 j) const;

    Accumulator::ptr copy () const;

    UInt32 getValue (const Indices& parameters) const;

    void vote (const ModelCoefficients& coeffs);

    Indices getMaxValue () const;

    void reset ();

  protected:
    void alloc ();
    void free ();

    UInt32** m_space;
};

#endif
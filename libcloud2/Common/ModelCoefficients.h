#ifndef __MODEL_COEFFICIENTS_H__
#define __MODEL_COEFFICIENTS_H__

#include "Types.h"
#include <vector>

class ModelCoefficients {
  public:
    typedef ModelCoefficients* ptr;
    typedef const ModelCoefficients* const_ptr;
    typedef std::vector <Float32>::iterator iterator;
    typedef std::vector <Float32>::const_iterator const_iterator;
    typedef std::vector <Float32>::reverse_iterator reverse_iterator;
    typedef std::vector <Float32>::const_reverse_iterator const_reverse_iterator;

    ModelCoefficients (UInt32 n);
    virtual ~ModelCoefficients ();

    const Float32& operator[] (UInt32 n) const;
    Float32& operator[] (UInt32 n);

    iterator begin ();
    const_iterator begin () const;

    iterator end ();
    const_iterator end () const;

    reverse_iterator rbegin ();
    const_reverse_iterator rbegin () const;

    reverse_iterator rend ();
    const_reverse_iterator rend () const;

    UInt32 getSize () const;

  protected:
    std::vector <Float32> m_coefficients;
};

#endif
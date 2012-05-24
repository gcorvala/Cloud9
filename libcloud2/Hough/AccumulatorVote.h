#ifndef __ACCUMULATOR_VOTE_H__
#define __ACCUMULATOR_VOTE_H__

#include "../Common/Types.h"
#include <vector>

class AccumulatorVote {
  public:
    AccumulatorVote (std::vector <Float32> parameters, UInt32 voter_id);
    virtual ~AccumulatorVote ();

    UInt8 getDimension () const;
    UInt32 getVoterId () const;
    void setVoterId (UInt32 voter_id);
    Float32 getWeight () const;
    void setWeight (Float32 weight);

    Float32& operator[] (UInt8 n);
    const Float32& operator[] (UInt8 n) const;

  protected:
    std::vector <Float32> m_parameters;
    Float32 m_weight;
    UInt32 m_voter_id;
};

class AccumulatorVote2D {
  public:
    AccumulatorVote2D (Float32 param1, Float32 param2);
    virtual ~AccumulatorVote2D ();
};

class AccumulatorVote3D {
  public:
    AccumulatorVote3D (Float32 param1, Float32 param2, Float32 param3);
    virtual ~AccumulatorVote3D ();
};

#endif
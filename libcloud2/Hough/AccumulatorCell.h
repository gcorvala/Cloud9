#ifndef __ACCUMULATOR_CELL_H__
#define __ACCUMULATOR_CELL_H__

#include "../Common/Types.h"
#include "../Common/Range.h"
#include "AccumulatorVote.h"
#include <vector>

class AccumulatorCell {
  public:
    AccumulatorCell ();
    virtual ~AccumulatorCell ();

    Float32 getValue () const;
    void addVote (const AccumulatorVote& vote);
    UInt32 getVotes () const;
    void getVoterIds (std::vector <UInt32>& voter_ids) const;
    void removeId (UInt32 id);
    Boolean containsId (UInt32 id) const;

  protected:
    std::vector <AccumulatorVote> m_votes;
};

#endif
#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__

#include "../Common/Types.h"
#include "../Common/Range.h"
#include "AccumulatorVote.h"
#include "AccumulatorCell.h"
#include <vector>
#include <map>

class Accumulator {
  public:
    Accumulator (const std::vector <Range>& ranges = std::vector <Range> ());
    virtual ~Accumulator ();

    void clear ();

    std::vector <Range> getRanges () const;
    void setRanges (const std::vector <Range>& ranges);
    
    void findMaxima (Float32 threshold, std::vector <Float32>& maxima_values, std::vector < std::vector <UInt32> >& maxima_voter_ids) const;
    void vote (const AccumulatorVote& vote);
    Float32 getValue (const std::vector <UInt32>& parameters);

  protected:
    void init ();
    static Boolean cellComparator (const AccumulatorCell& c1, const AccumulatorCell& c2);

    std::vector <AccumulatorCell> m_space;
    std::vector <Range> m_ranges;
    std::vector <Float32> m_min;
    std::vector <Float32> m_max;
    std::vector <Float32> m_bin_size;
};

#endif
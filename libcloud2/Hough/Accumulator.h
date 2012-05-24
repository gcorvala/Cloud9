#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__

#include "../Common/Types.h"
#include "../Common/Range.h"
#include "AccumulatorVote.h"
#include "AccumulatorCell.h"
#include <vector>

class Accumulator {
  public:
    Accumulator (const std::vector <Range>& ranges);
    Accumulator (const std::vector <Float32> min = std::vector <Float32> (), const std::vector <Float32> max = std::vector <Float32> (), const std::vector <Float32> bin_size = std::vector <Float32> ());
    virtual ~Accumulator ();

    void clear ();

    void setMin (const std::vector <Float32> min);
    const std::vector <Float32> getMin () const;

    void setMax (const std::vector <Float32> max);
    const std::vector <Float32> getMax () const;

    void setBinSize (const std::vector <Float32> bin_size);
    const std::vector <Float32> getBinSize () const;

    void findMaxima (Float32 threshold, std::vector <Float32>& maxima_values, std::vector < std::vector <UInt32> >& maxima_voter_ids) const;
    void vote (const AccumulatorVote& vote);

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
#include "AccumulatorCell.h"

#include <algorithm>
#include <functional>

AccumulatorCell::AccumulatorCell ()
{
}

AccumulatorCell::~AccumulatorCell ()
{
}

Float32
AccumulatorCell::getValue () const
{
  std::vector <AccumulatorVote>::const_iterator it;
  Float32 value = 0;

  for (it = m_votes.begin (); it != m_votes.end (); ++it) {
    value += it->getWeight ();
  }

  return value;
}

void
AccumulatorCell::addVote (const AccumulatorVote& vote)
{
  if (containsId (vote.getVoterId ())) {
    PRINT (vote.getVoterId ());
    ERROR ("id already in this cell");
  }
  m_votes.push_back (vote);
}

UInt32
AccumulatorCell::getVotes () const
{
  return m_votes.size ();
}

void
AccumulatorCell::getVoterIds (std::vector <UInt32>& voter_ids) const
{
  std::vector <AccumulatorVote>::const_iterator it;

  voter_ids.clear ();

  for (it = m_votes.begin (); it != m_votes.end (); ++it) {
    voter_ids.push_back (it->getVoterId ());
  }
}

void
AccumulatorCell::removeId (UInt32 id)
{
  std::vector <AccumulatorVote>::iterator it;

  for (it = m_votes.begin (); it != m_votes.end (); ++it) {
    if (it->getVoterId () == id) {
      it = m_votes.erase (it) - 1;
    }
  }
}

Boolean
AccumulatorCell::containsId (UInt32 id) const
{
  std::vector <AccumulatorVote>::const_iterator it;

  for (it = m_votes.begin (); it != m_votes.end (); ++it) {
    if (it->getVoterId () == id) {
      return true;
    }
  }
  return false;
}
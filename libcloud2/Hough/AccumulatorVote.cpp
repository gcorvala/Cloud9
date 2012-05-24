#include "AccumulatorVote.h"

AccumulatorVote::AccumulatorVote (std::vector <Float32> parameters, UInt32 voter_id)
  :m_parameters (parameters)
  ,m_voter_id (voter_id)
  ,m_weight (1.0)
{
}

AccumulatorVote::~AccumulatorVote ()
{
}

UInt8
AccumulatorVote::getDimension () const
{
  return m_parameters.size ();
}

UInt32
AccumulatorVote::getVoterId () const
{
  return m_voter_id;
}

void
AccumulatorVote::setVoterId (UInt32 voter_id)
{
  m_voter_id = voter_id;
}

Float32
AccumulatorVote::getWeight () const
{
  return m_weight;
}

void
AccumulatorVote::setWeight (Float32 weight)
{
  m_weight = weight;
}

Float32&
AccumulatorVote::operator[] (UInt8 n)
{
  return m_parameters[n];
}

const Float32&
AccumulatorVote::operator[] (UInt8 n) const
{
  return m_parameters[n];
}
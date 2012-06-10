#include "Timer.h"

Timer::Timer ()
{
  m_start_time = clock ();
}

Timer::~Timer ()
{
}

void
Timer::restart ()
{
  m_start_time = clock ();
}

Float32
Timer::getElapsed () const
{
  return Float32 (clock () - m_start_time) / CLOCKS_PER_SEC;
}
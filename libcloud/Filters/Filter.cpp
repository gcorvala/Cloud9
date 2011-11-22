#include "Filter.h"

#include <cfloat>

Filter::Filter ()
  : limit_min(-FLT_MAX), limit_max(FLT_MAX)
{
}

Filter::~Filter ()
{
}
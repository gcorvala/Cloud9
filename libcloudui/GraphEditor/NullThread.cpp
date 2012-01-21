#include "NullThread.h"

NullThread::NullThread (QObject* parent )
  :EstimatorThread<UInt32, UInt32>(parent)
{

}

NullThread::~NullThread ()
{
}

void
NullThread::run ()
{
  msleep (500);
}
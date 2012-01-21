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
  qDebug ("NullThread::run");
  msleep (3000);
  output = new UInt32(10); 
  qDebug ("NullThread::run");
}
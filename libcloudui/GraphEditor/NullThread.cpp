#include "NullThread.h"

NullThread::NullThread (QObject* parent )
  :NodeThread(parent)
{

}

NullThread::~NullThread ()
{
}

void
NullThread::run ()
{
  qDebug ("NullThread::run start");
  msleep (500);
  qDebug ("NullThread::run end");
}
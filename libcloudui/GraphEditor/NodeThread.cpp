#include "NodeThread.h"

NodeThread::NodeThread (Node* parent)
  :QThread(parent)
{
  connect (this, SIGNAL (started ()), parent, SLOT (setRunning ()));
  connect (this, SIGNAL (finished ()), parent, SLOT (unsetRunning ()));
  connect (this, SIGNAL (finished ()), parent, SLOT (endProcess ()));
  
}

NodeThread::~NodeThread ()
{
}
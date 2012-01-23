#ifndef __NULL_THREAD_H__
#define __NULL_THREAD_H__

#include "NodeThread.h"

class NullThread : public NodeThread {
  public:
    NullThread (QObject* parent = 0);
    virtual ~NullThread ();

    void run ();

  protected:

  private:
};

#endif
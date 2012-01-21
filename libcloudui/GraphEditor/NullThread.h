#ifndef __ESTIMATOR_THREAD_H__
#define __NULL_THREAD_H__

#include "EstimatorThread.h"

class NullThread : public EstimatorThread<UInt32, UInt32> {
  public:
    NullThread (QObject* parent = 0);
    virtual ~NullThread ();

    void run ();

  protected:

  private:
};

#endif
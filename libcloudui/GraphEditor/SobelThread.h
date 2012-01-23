#ifndef __SOBEL_THREAD_H__
#define __SOBLE_THREAD_H__

#include "EstimatorThread.h"
#include <QMetaType>

class SobelThread : public EstimatorThread<UInt8, double> {
  public:
    SobelThread (QObject* parent = 0);
    virtual ~SobelThread ();

    void run ();

  protected:

  private:
};

#endif
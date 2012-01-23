#ifndef __IMAGE_READER_THREAD_H__
#define __IMAGE_READER_THREAD_H__

#include "NodeThread.h"
#include <libcloud/2D/Matrix.h>

class ImageReaderThread : public NodeThread {
  public:
    ImageReaderThread (QObject* parent = 0);
    virtual ~ImageReaderThread ();

    void run ();

    void setOutputPtr (Matrix<UInt8>* ptr);

  protected:

  private:
    QString path;
    Matrix<UInt8>* output;
};

#endif
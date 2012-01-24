#ifndef __SOBEL_NODE_H__
#define __SOBEL_NODE_H__

#include "Node.h"
#include <libcloud/2D/Image.h>
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/SobelEstimator.h>

class SobelNode : public Node {
  class SobelThread : public NodeThread {
    public:
      SobelThread (Node* parent = 0);
      virtual ~SobelThread ();

      void run ();

      void setInputPtr (const Matrix<UInt8>* ptr);
      void setOutputPtr (Matrix<UInt8>* ptr);

    private:
      SobelEstimator Sobel;
      const Matrix<UInt8>* input;
      Matrix<UInt8>* output;
  };

  public:
    SobelNode ();
    virtual ~SobelNode ();

    void process ();

  protected:
    SobelThread thread;
    Matrix<UInt8> output;
    Matrix<UInt8>* input;
};

#endif
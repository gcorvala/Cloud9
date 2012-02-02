#ifndef __SOBEL_NODE_H__
#define __SOBEL_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Image.h>
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/SobelEstimator.h>

class SobelNode : public Node {
  class SobelThread : public NodeThread {
    public:
      SobelThread (Node* parent = 0);
      virtual ~SobelThread ();

      void run ();

      SobelEstimator Sobel;
      Matrix<UInt8>* input;
      Matrix<UInt8> output;
  };

  public:
    SobelNode ();
    virtual ~SobelNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    SobelThread thread;
};

#endif
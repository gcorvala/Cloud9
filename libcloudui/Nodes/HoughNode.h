#ifndef __HOUGH_NODE_H__
#define __HOUGH_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/HoughEstimator.h>

class HoughNode : public Node {
  class HoughThread : public NodeThread {
    public:
      HoughThread (Node* parent = 0);
      virtual ~HoughThread ();

      void run ();

      HoughEstimator estimator;
      Matrix<UInt8>* input;
      Matrix<UInt8> output;
  };

  public:
    HoughNode ();
    virtual ~HoughNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    HoughThread thread;
};

#endif
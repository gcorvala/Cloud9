#ifndef __CANNY_NODE_H__
#define __CANNY_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/CannyEstimator.h>

class CannyNode : public Node {
  class CannyThread : public NodeThread {
    public:
      CannyThread (Node* parent = 0);
      virtual ~CannyThread ();

      void run ();

      CannyEstimator canny;
      Matrix<UInt8>* input;
      Matrix<UInt8> output;
  };

  public:
    CannyNode ();
    virtual ~CannyNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    CannyThread thread;
};

#endif
#ifndef __GAUSSIAN_NODE_H__
#define __GAUSSIAN_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Image.h>
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/GaussianEstimator.h>

class GaussianNode : public Node {
  class GaussianThread : public NodeThread {
    public:
      GaussianThread (Node* parent = 0);
      virtual ~GaussianThread ();

      void run ();

      GaussianEstimator gaussian;
      Matrix<UInt8>* input;
      Matrix<UInt8> output;
  };

  public:
    GaussianNode ();
    virtual ~GaussianNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    GaussianThread thread;
};

#endif
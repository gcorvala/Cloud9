#ifndef __GAUSSIAN_NODE_H__
#define __GAUSSIAN_NODE_H__

#include "Node.h"
#include <libcloud/2D/Image.h>
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/GaussianEstimator.h>

class GaussianNode : public Node {
  class GaussianThread : public NodeThread {
    public:
      GaussianThread (Node* parent = 0);
      virtual ~GaussianThread ();

      void run ();

      void setInputPtr (Matrix<UInt8>* ptr);
      void setOutputPtr (Matrix<UInt8>* ptr);

    private:
      GaussianEstimator gaussian;
      Matrix<UInt8>* input;
      Matrix<UInt8>* output;
  };

  public:
    GaussianNode ();
    virtual ~GaussianNode ();

    void process ();

  protected:
    GaussianThread thread;
    Matrix<UInt8> input;
    Matrix<UInt8> output;
};

#endif
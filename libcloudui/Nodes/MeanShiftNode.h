#ifndef __MEAN_SHIFT_NODE_H__
#define __MEAN_SHIFT_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/MeanShiftEstimator.h>

class MeanShiftNode : public Node {
  class MeanShiftThread : public NodeThread {
    public:
      MeanShiftThread (Node* parent = 0);
      virtual ~MeanShiftThread ();

      void run ();

      MeanShiftEstimator estimator;
      Matrix<UInt32>* input;
      Matrix<UInt8> output;
  };

  public:
    MeanShiftNode ();
    virtual ~MeanShiftNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    MeanShiftThread thread;
};

#endif
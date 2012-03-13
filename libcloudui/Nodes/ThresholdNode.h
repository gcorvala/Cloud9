#ifndef __THRESHOLD_NODE_H__
#define __THRESHOLD_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/ThresholdEstimator.h>

class ThresholdNode : public Node {
  class ThresholdThread : public NodeThread {
    public:
      ThresholdThread (Node* parent = 0);
      virtual ~ThresholdThread ();

      void run ();

      ThresholdEstimator<UInt8> threshold;
      Matrix<UInt8>* input;
      Matrix<UInt8> output;
  };

  public:
    ThresholdNode ();
    virtual ~ThresholdNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    ThresholdThread thread;
};

#endif
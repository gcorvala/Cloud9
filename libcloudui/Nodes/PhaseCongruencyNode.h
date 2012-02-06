#ifndef __PHASE_CONGRUENCY_NODE_H__
#define __PHASE_CONGRUENCY_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Matrix.h>
#include <libcloud/2D/PhaseCongruencyEstimator.h>

class PhaseCongruencyNode : public Node {
  class PhaseCongruencyThread : public NodeThread {
    public:
      PhaseCongruencyThread (Node* parent = 0);
      virtual ~PhaseCongruencyThread ();

      void run ();

      PhaseCongruencyEstimator PhaseCongruency;
      Matrix<UInt8>* input;
      Matrix<UInt8> output;
  };

  public:
    PhaseCongruencyNode ();
    virtual ~PhaseCongruencyNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    PhaseCongruencyThread thread;
};

#endif
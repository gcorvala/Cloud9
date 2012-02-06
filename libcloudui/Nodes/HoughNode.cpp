#include "HoughNode.h"

#include "../GraphEditor/IntegerProperty.h"

HoughNode::HoughNode ()
  :Node("Hough")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
  addProperty ("n-theta", new IntegerProperty ("# theta", 1, 4096, thread.estimator.getNTheta ()));
  addProperty ("n-rho", new IntegerProperty ("# rho", 1, 4096, thread.estimator.getNRho ()));
}

HoughNode::~HoughNode ()
{
}

void
HoughNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt8>*> ();
  thread.estimator.setNTheta (((IntegerProperty*) properties["n-theta"])->getValue ());
  thread.estimator.setNRho (((IntegerProperty*) properties["n-rho"])->getValue ());
}

void
HoughNode::process ()
{
  thread.start ();
}

void
HoughNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

HoughNode::HoughThread::HoughThread (Node* parent)
  :NodeThread(parent)
{
}

HoughNode::HoughThread::~HoughThread ()
{
}

void
HoughNode::HoughThread::run ()
{
  estimator.compute (*input, output);
}
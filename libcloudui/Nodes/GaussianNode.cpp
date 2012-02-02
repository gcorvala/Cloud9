#include "GaussianNode.h"

GaussianNode::GaussianNode ()
  :Node("Gaussian")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
}

GaussianNode::~GaussianNode ()
{
}

void
GaussianNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt8>*> ();
}

void
GaussianNode::process ()
{
  thread.start ();
}

void
GaussianNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

GaussianNode::GaussianThread::GaussianThread (Node* parent)
  :NodeThread(parent)
{
}

GaussianNode::GaussianThread::~GaussianThread ()
{
}

void
GaussianNode::GaussianThread::run ()
{
  gaussian.compute (*input, output);
}
#include "ThresholdNode.h"

#include "../GraphEditor/RealProperty.h"

ThresholdNode::ThresholdNode ()
  :Node("Threshold")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
  addProperty ("threshold", new RealProperty ("Threshold", 0, 255, thread.threshold.getThreshold ()));
}

ThresholdNode::~ThresholdNode ()
{
}

void
ThresholdNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt8>*> ();
  thread.threshold.setThreshold (((RealProperty*) properties["threshold"])->getValue ());
}

void
ThresholdNode::process ()
{
  thread.start ();
}

void
ThresholdNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

ThresholdNode::ThresholdThread::ThresholdThread (Node* parent)
  :NodeThread(parent)
{
}

ThresholdNode::ThresholdThread::~ThresholdThread ()
{
}

void
ThresholdNode::ThresholdThread::run ()
{
  threshold.compute (*input, output);
}
#include "MeanShiftNode.h"

#include "../GraphEditor/IntegerProperty.h"

MeanShiftNode::MeanShiftNode ()
  :Node("MeanShift")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
  addProperty ("window-width", new IntegerProperty ("Window width", 2, 64, thread.estimator.getWindowWidth ()));
}

MeanShiftNode::~MeanShiftNode ()
{
}

void
MeanShiftNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt32>*> ();
  thread.estimator.setWindowWidth (((IntegerProperty*) properties["window-width"])->getValue ());
}

void
MeanShiftNode::process ()
{
  thread.start ();
}

void
MeanShiftNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

MeanShiftNode::MeanShiftThread::MeanShiftThread (Node* parent)
  :NodeThread(parent)
{
}

MeanShiftNode::MeanShiftThread::~MeanShiftThread ()
{
}

void
MeanShiftNode::MeanShiftThread::run ()
{
  estimator.compute (*input, output);
}
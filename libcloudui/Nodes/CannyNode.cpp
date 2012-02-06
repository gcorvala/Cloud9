#include "CannyNode.h"

#include "../GraphEditor/RealProperty.h"

CannyNode::CannyNode ()
  :Node("Canny")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
  addProperty ("low-threshold", new RealProperty ("Low threshold", 0, 255, thread.canny.getLowThreshold ()));
  addProperty ("high-threshold", new RealProperty ("High threshold", 0, 255, thread.canny.getHighThreshold ()));
}

CannyNode::~CannyNode ()
{
}

void
CannyNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt8>*> ();
  thread.canny.setLowThreshold (((RealProperty*) properties["low-threshold"])->getValue ());
  thread.canny.setHighThreshold (((RealProperty*) properties["high-threshold"])->getValue ());
}

void
CannyNode::process ()
{
  thread.start ();
}

void
CannyNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

CannyNode::CannyThread::CannyThread (Node* parent)
  :NodeThread(parent)
{
}

CannyNode::CannyThread::~CannyThread ()
{
}

void
CannyNode::CannyThread::run ()
{
  canny.compute (*input, output);
}
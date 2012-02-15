#include "CropBoxNode.h"

#include "../../GraphEditor/RealProperty.h"

CropBoxNode::CropBoxNode ()
  :Node("CropBox")
  ,thread(this)
{
  addOutputAnchor ("cloud");
  addInputAnchor ("cloud");

  addProperty ("min-x", new RealProperty ("X Min", -100000, 100000, thread.filter.getMin ().x));
  addProperty ("min-y", new RealProperty ("Y Min", -100000, 100000, thread.filter.getMin ().y));
  addProperty ("min-z", new RealProperty ("Z Min", -100000, 100000, thread.filter.getMin ().z));
  addProperty ("max-x", new RealProperty ("X Max", -100000, 100000, thread.filter.getMax ().x));
  addProperty ("max-y", new RealProperty ("Y Max", -100000, 100000, thread.filter.getMax ().y));
  addProperty ("max-z", new RealProperty ("Z Max", -100000, 100000, thread.filter.getMax ().z));
}

CropBoxNode::~CropBoxNode ()
{
}

void
CropBoxNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["cloud"]->getValue<PointCloud*> ();

  Point min (((RealProperty*) properties["min-x"])->getValue (),
             ((RealProperty*) properties["min-y"])->getValue (),
             ((RealProperty*) properties["min-z"])->getValue ());
  Point max (((RealProperty*) properties["max-x"])->getValue (),
             ((RealProperty*) properties["max-y"])->getValue (),
             ((RealProperty*) properties["max-z"])->getValue ());

  thread.filter.setMin (min);
  thread.filter.setMax (max);
}

void
CropBoxNode::process ()
{
  thread.start ();
}

void
CropBoxNode::postProcess ()
{
  outputs["cloud"]->setValue (&(thread.output));
  Node::postProcess ();
}

CropBoxNode::CropBoxThread::CropBoxThread (Node* parent)
  :NodeThread(parent)
{
}

CropBoxNode::CropBoxThread::~CropBoxThread ()
{
}

void
CropBoxNode::CropBoxThread::run ()
{
  filter.compute (*input, output);
}
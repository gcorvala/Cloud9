#include "Hough3dNode.h"

#include "../../GraphEditor/RealProperty.h"

Hough3dNode::Hough3dNode ()
  :Node("Hough3d")
  ,thread(this)
{
  addOutputAnchor ("cloud");
  addInputAnchor ("cloud");
}

Hough3dNode::~Hough3dNode ()
{
}

void
Hough3dNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["cloud"]->getValue<PointCloud*> ();
}

void
Hough3dNode::process ()
{
  thread.start ();
}

void
Hough3dNode::postProcess ()
{
  outputs["cloud"]->setValue (&(thread.output));
  Node::postProcess ();
}

Hough3dNode::Hough3dThread::Hough3dThread (Node* parent)
  :NodeThread(parent)
{
}

Hough3dNode::Hough3dThread::~Hough3dThread ()
{
}

void
Hough3dNode::Hough3dThread::run ()
{
  filter.compute (*input, output);
}
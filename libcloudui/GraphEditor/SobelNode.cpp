#include "SobelNode.h"

SobelNode::SobelNode ()
  :Node("Sobel")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
}

SobelNode::~SobelNode ()
{
}

void
SobelNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt8>*> ();
}

void
SobelNode::process ()
{
  thread.start ();
}

void
SobelNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

SobelNode::SobelThread::SobelThread (Node* parent)
  :NodeThread(parent)
{
}

SobelNode::SobelThread::~SobelThread ()
{
}

void
SobelNode::SobelThread::run ()
{
  Matrix<double> tmp;
  Sobel.compute (*input, tmp);
  output = tmp;
}
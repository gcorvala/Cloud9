#include "TestNode.h"

TestNode::TestNode ()
  :Node("Test")
{
  addOutputAnchor (new OutputAnchor (this), "image");
  addInputAnchor (new InputAnchor (this), "image");
}

TestNode::~TestNode ()
{
}

void
TestNode::process ()
{
  Image* image;

  setRunning ();
  qDebug ("TestNode::process");
  image = inputs["image"]->var->value<Image*> ();
  qDebug ("TestNode::image %d:%d", image->getRows (), image->getCols ());
  endProcess ();
  unsetRunning ();
}
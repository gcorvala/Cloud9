#include "TestNode.h"

TestNode::TestNode ()
  :Node("Test")
{
  addOutputAnchor ("image", new OutputAnchor (this));
  addInputAnchor ("image", new InputAnchor (this));
}

TestNode::~TestNode ()
{
}

Q_DECLARE_METATYPE (Matrix<UInt8> *);

void
TestNode::endProcess ()
{
  Matrix<UInt8>* image = inputs["image"]->var.value<Matrix<UInt8>*> ();

  qDebug ("TestNode::image %d:%d", image->getRows (), image->getCols ());
}
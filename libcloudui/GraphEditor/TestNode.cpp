#include "TestNode.h"

TestNode::TestNode ()
  :Node("Test")
{
  addOutputAnchor (new OutputAnchor (this));
  addInputAnchor (new InputAnchor (this));
}

TestNode::~TestNode ()
{
}

Q_DECLARE_METATYPE (Matrix<UInt8> *);

void
TestNode::endProcess ()
{
  Matrix<UInt8>* image = input_anchors[0]->var.value<Matrix<UInt8>*> ();

  qDebug ("TestNode::image %d:%d", image->getRows (), image->getCols ());
}
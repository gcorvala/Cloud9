#include "TestNode.h"

#include "../GraphEditor/IntegerProperty.h"
#include "../GraphEditor/RealProperty.h"

TestNode::TestNode ()
  :Node("Test")
{
  addProperty ("test", new IntegerProperty ("Test prop", -10, 10, 3));
  addProperty ("test2", new IntegerProperty ("Test2 prop", -10, 10, 3));
  addProperty ("test3", new IntegerProperty ("Test2 prop", -10, 10, 3));
  addProperty ("real", new RealProperty ("Real prop", -10, 10, 0));
}

TestNode::~TestNode ()
{
}

void
TestNode::process ()
{
  //getPropertyWidget ()->show ();

  Image* image;

  setRunning ();
  postProcess ();
  unsetRunning ();
}
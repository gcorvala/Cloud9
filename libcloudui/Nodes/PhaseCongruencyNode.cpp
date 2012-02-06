#include "PhaseCongruencyNode.h"

#include "../GraphEditor/IntegerProperty.h"

PhaseCongruencyNode::PhaseCongruencyNode ()
  :Node("PhaseCongruency")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
  addProperty ("aperture", new IntegerProperty ("Window aperture", 2, 5, 3));
}

PhaseCongruencyNode::~PhaseCongruencyNode ()
{
}

void
PhaseCongruencyNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt8>*> ();
  thread.PhaseCongruency.setAperture (((IntegerProperty*) properties["aperture"])->getValue ());
}

void
PhaseCongruencyNode::process ()
{
  thread.start ();
}

void
PhaseCongruencyNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

PhaseCongruencyNode::PhaseCongruencyThread::PhaseCongruencyThread (Node* parent)
  :NodeThread(parent)
{
}

PhaseCongruencyNode::PhaseCongruencyThread::~PhaseCongruencyThread ()
{
}

void
PhaseCongruencyNode::PhaseCongruencyThread::run ()
{
  PhaseCongruency.compute (*input, output);
}
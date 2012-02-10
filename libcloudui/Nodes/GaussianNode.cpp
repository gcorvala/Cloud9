#include "GaussianNode.h"

#include "../GraphEditor/IntegerProperty.h"
#include "../GraphEditor/RealProperty.h"

GaussianNode::GaussianNode ()
  :Node("Gaussian")
  ,thread(this)
{
  addOutputAnchor ("image");
  addInputAnchor ("image");
  addProperty ("aperture", new IntegerProperty ("Aperture", 3, 9, thread.gaussian.getAperture ()));
  addProperty ("sigma", new RealProperty ("Sigma", 0.1, 10, thread.gaussian.getSigma ()));
}

GaussianNode::~GaussianNode ()
{
}

void
GaussianNode::preProcess ()
{
  Node::preProcess ();
  thread.input = inputs["image"]->getValue<Matrix<UInt8>*> ();
  thread.gaussian.setAperture (((IntegerProperty*) properties["aperture"])->getValue ());
  thread.gaussian.setSigma (((RealProperty*) properties["sigma"])->getValue ());
}

void
GaussianNode::process ()
{
  thread.start ();
}

void
GaussianNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

GaussianNode::GaussianThread::GaussianThread (Node* parent)
  :NodeThread(parent)
{
}

GaussianNode::GaussianThread::~GaussianThread ()
{
}

void
GaussianNode::GaussianThread::run ()
{
  Matrix<UInt32> input32, output32;
  input32 = *input;
  output32 = output;
  gaussian.compute (input32, output32);
  output = output32;
}
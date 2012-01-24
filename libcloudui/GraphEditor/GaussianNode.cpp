#include "GaussianNode.h"

Q_DECLARE_METATYPE (Image*);
Q_DECLARE_METATYPE (Matrix<UInt8>*);

GaussianNode::GaussianNode ()
  :Node("Gaussian")
  ,thread(this)
{
  OutputAnchor* out;
  thread.setOutputPtr (&output);

  out = new OutputAnchor (this);
  out->var.setValue (&output);
  addOutputAnchor (out, "image");

  addInputAnchor (new InputAnchor (this), "image");
}

GaussianNode::~GaussianNode ()
{
}

void
GaussianNode::process ()
{
  Image* image = inputs["image"]->var.value<Image*> ();

  input = image->getYChannel ();

  thread.setInputPtr (&input);

  thread.start ();
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
  gaussian.compute (*input, *output);
}

void
GaussianNode::GaussianThread::setInputPtr (Matrix<UInt8>* ptr)
{
  input = ptr;
}
void
GaussianNode::GaussianThread::setOutputPtr (Matrix<UInt8>* ptr)
{
  output = ptr;
}
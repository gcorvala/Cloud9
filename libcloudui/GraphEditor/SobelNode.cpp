#include "SobelNode.h"

SobelNode::SobelNode ()
  :Node("Sobel")
  ,thread(this)
{
  OutputAnchor* out;

  thread.setOutputPtr (&output);

  out = new OutputAnchor (this);
  out->var.setValue (&output);
  addOutputAnchor (out, "image");

  addInputAnchor (new InputAnchor (this), "image");
}

SobelNode::~SobelNode ()
{
}

void
SobelNode::process ()
{
  input = inputs["image"]->var->value<Matrix<UInt8>*> ();

  thread.setInputPtr (input);

  thread.start ();
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
  *output = tmp;
}

void
SobelNode::SobelThread::setInputPtr (const Matrix<UInt8>* ptr)
{
  input = ptr;
}
void
SobelNode::SobelThread::setOutputPtr (Matrix<UInt8>* ptr)
{
  output = ptr;
}
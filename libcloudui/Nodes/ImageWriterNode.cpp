#include "ImageWriterNode.h"
#include "../GraphEditor/PathProperty.h"

ImageWriterNode::ImageWriterNode ()
  :Node("Image Writer")
  ,thread(this)
{
  addInputAnchor ("image");
  addProperty ("output-file", new PathProperty ("Output file", PathProperty::SaveFile));
}

ImageWriterNode::~ImageWriterNode ()
{
}

void
ImageWriterNode::preProcess ()
{
  Node::preProcess ();
  thread.path = ((PathProperty*) properties["output-file"])->getValue ();
  thread.input = inputs["image"]->getValue<Image*> ();
}

void
ImageWriterNode::process ()
{
  thread.start ();
}

void
ImageWriterNode::postProcess ()
{
  Node::postProcess ();
}

ImageWriterNode::ImageWriterThread::ImageWriterThread (Node* parent)
  :NodeThread(parent)
{
}

ImageWriterNode::ImageWriterThread::~ImageWriterThread ()
{
}

void
ImageWriterNode::ImageWriterThread::run ()
{
  QImage output (input->getCols (), input->getRows (), QImage::Format_RGB888);

  for (UInt32 i = 0; i < output.height (); ++i) {
    for (UInt32 j = 0; j < output.width (); ++j) {
      Color c = input->getPixel (i, j);
      output.setPixel (j, i, qRgb (c.r, c.g, c.b));
    }
  }

  output.save (path);
}
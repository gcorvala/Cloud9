#include "ImageReaderNode.h"
#include "../GraphEditor/PathProperty.h"

ImageReaderNode::ImageReaderNode ()
  :Node("Image Reader")
  ,thread(this)
{
  addOutputAnchor ("image");
  addProperty ("input-file", new PathProperty ("Input file"));
}

ImageReaderNode::~ImageReaderNode ()
{
}

void
ImageReaderNode::preProcess ()
{
  Node::preProcess ();
  thread.path = ((PathProperty*) properties["input-file"])->getValue ();
}

void
ImageReaderNode::process ()
{
  thread.start ();
}

void
ImageReaderNode::postProcess ()
{
  outputs["image"]->setValue (&(thread.output));
  Node::postProcess ();
}

ImageReaderNode::ImageReaderThread::ImageReaderThread (Node* parent)
  :NodeThread(parent)
{
}

ImageReaderNode::ImageReaderThread::~ImageReaderThread ()
{
}

void
ImageReaderNode::ImageReaderThread::run ()
{
  QImage image (path);

  output.resize (image.height (), image.width ());

  for (UInt32 i = 0; i < image.height (); ++i) {
    for (UInt32 j = 0; j < image.width (); ++j) {
      QRgb c = image.pixel (j, i);
      output.setPixel (i, j, Color (qRed (c), qGreen (c), qBlue (c)));
    }
  }
}
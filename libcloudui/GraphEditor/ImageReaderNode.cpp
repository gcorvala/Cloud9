#include "ImageReaderNode.h"

Q_DECLARE_METATYPE (Image*);

ImageReaderNode::ImageReaderNode ()
  :Node("Image Reader")
  ,thread(this)
{
  OutputAnchor* out;

  thread.setOutputPtr (&image);

  out = new OutputAnchor (this);
  out->var.setValue (&image);
  addOutputAnchor (out, "image");
}

ImageReaderNode::~ImageReaderNode ()
{
}

void
ImageReaderNode::process ()
{
  thread.start ();
}

ImageReaderNode::ImageReaderThread::ImageReaderThread (Node* parent)
  :NodeThread(parent)
{
  path = "building.jpg";
}

ImageReaderNode::ImageReaderThread::~ImageReaderThread ()
{
}

void
ImageReaderNode::ImageReaderThread::run ()
{
  qDebug ("ImageReaderThread::run start");
  QImage image (path);
  qDebug ("ImageReaderThread::run %d:%d", image.height (), image.width ());

  output->resize (image.height (), image.width ());

  for (UInt32 i = 0; i < image.height (); ++i) {
    for (UInt32 j = 0; j < image.width (); ++j) {
      QRgb c = image.pixel (j, i);
      output->setPixel (i, j, Color (qRed (c), qGreen (c), qBlue (c)));
    }
  }
  qDebug ("ImageReaderThread::run end");
}

void
ImageReaderNode::ImageReaderThread::setOutputPtr (Image* ptr)
{
  output = ptr;
}
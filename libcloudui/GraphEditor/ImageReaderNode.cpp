#include "ImageReaderNode.h"

#include "ImageReaderThread.h"

Q_DECLARE_METATYPE (Matrix<UInt8> *);
Q_DECLARE_METATYPE (Matrix<double> *);

ImageReaderNode::ImageReaderNode ()
  :Node("Image Reader")
{
  ImageReaderThread* reader = new ImageReaderThread ();
  reader->setOutputPtr (&image);

  setNodeThread (reader);

  OutputAnchor* out = new OutputAnchor (this);
  out->var.setValue (&image);
  addOutputAnchor ("image", out);
}

ImageReaderNode::~ImageReaderNode ()
{
}

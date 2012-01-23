#ifndef __IMAGE_READER_NODE_H__
#define __IMAGE_READER_NODE_H__

#include "Node.h"
#include <libcloud/2D/Matrix.h>

class ImageReaderNode : public Node {
  public:
    ImageReaderNode ();
    virtual ~ImageReaderNode ();

  protected:
    Matrix<UInt8> image;
};

#endif
#ifndef __IMAGE_NODE_H__
#define __IMAGE_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Image.h>
#include <libcloud/2D/Matrix.h>

class ImageNode : public Node {
  public:
    ImageNode ();
    virtual ~ImageNode ();

    void process ();
};

#endif
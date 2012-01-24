#ifndef __VIEWER_NODE_H__
#define __VIEWER_NODE_H__

#include "Node.h"
#include <libcloud/2D/Matrix.h>

class ViewerNode : public Node {
  public:
    ViewerNode ();
    virtual ~ViewerNode ();

    void process ();
  private:
    Matrix<UInt8> *image;
};

#endif
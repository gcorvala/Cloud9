#ifndef __TEST_NODE_H__
#define __TEST_NODE_H__

#include "Node.h"
#include <libcloud/2D/Matrix.h>

class TestNode : public Node {
  public:
    TestNode ();
    virtual ~TestNode ();

    void endProcess ();

  protected:
    Matrix<UInt8> image;
};

#endif
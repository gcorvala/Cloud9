#ifndef __TEST_NODE_H__
#define __TEST_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Image.h>

class TestNode : public Node {
  public:
    TestNode ();
    virtual ~TestNode ();

    void process ();
};

#endif
#ifndef __NODE_THREAD_H__
#define __NODE_THREAD_H__

#include <QThread>
#include "Node.h"

class NodeThread : public QThread {
  public:
    NodeThread (Node* parent);
    virtual ~NodeThread ();

    void run () = 0;
};

#endif
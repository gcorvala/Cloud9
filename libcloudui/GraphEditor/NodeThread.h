#ifndef __NODE_THREAD_H__
#define __NODE_THREAD_H__

#include <QThread>

class NodeThread : public QThread {
  public:
    NodeThread (QObject* parent = 0);
    virtual ~NodeThread ();

    void run () = 0;
};

#endif
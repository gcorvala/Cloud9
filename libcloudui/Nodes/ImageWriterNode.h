#ifndef __IMAGE_WRITER_NODE_H__
#define __IMAGE_WRITER_NODE_H__

#include "../GraphEditor/Node.h"
#include <libcloud/2D/Image.h>

class ImageWriterNode : public Node {
  class ImageWriterThread : public NodeThread {
    public:
      ImageWriterThread (Node* parent = 0);
      virtual ~ImageWriterThread ();

      void run ();

      QString path;
      Image* input;
  };

  public:
    ImageWriterNode ();
    virtual ~ImageWriterNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    ImageWriterThread thread;
};

#endif
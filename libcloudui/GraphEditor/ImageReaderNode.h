#ifndef __IMAGE_READER_NODE_H__
#define __IMAGE_READER_NODE_H__

#include "Node.h"
#include <libcloud/2D/Image.h>

class ImageReaderNode : public Node {
  class ImageReaderThread : public NodeThread {
    public:
      ImageReaderThread (Node* parent = 0);
      virtual ~ImageReaderThread ();

      void run ();

      void setOutputPtr (Image* ptr);

    private:
      QString path;
      Image* output;
  };

  public:
    ImageReaderNode ();
    virtual ~ImageReaderNode ();

    void process ();

  protected:
    ImageReaderThread thread;
    Image image;
};

#endif
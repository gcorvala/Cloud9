#ifndef __POINT_CLOUD_READER_NODE_H__
#define __POINT_CLOUD_READER_NODE_H__

#include "../../GraphEditor/Node.h"
#include <libcloud/Common/PointCloud.h>

class PointCloudReaderNode : public Node {
  class PointCloudReaderThread : public NodeThread {
    public:
      PointCloudReaderThread (Node* parent = 0);
      virtual ~PointCloudReaderThread ();

      void run ();

      QString path;
      PointCloud output;
  };

  public:
    PointCloudReaderNode ();
    virtual ~PointCloudReaderNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    PointCloudReaderThread thread;
};

#endif
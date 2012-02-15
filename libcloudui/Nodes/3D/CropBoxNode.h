#ifndef __CROP_BOX_NODE_H__
#define __CROP_BOX_NODE_H__

#include "../../GraphEditor/Node.h"
#include <libcloud/Common/PointCloud.h>
#include <libcloud/Filters/CropBoxFilter.h>

class CropBoxNode : public Node {
  class CropBoxThread : public NodeThread {
    public:
      CropBoxThread (Node* parent = 0);
      virtual ~CropBoxThread ();

      void run ();

      CropBoxFilter filter;
      PointCloud* input;
      PointCloud output;
  };

  public:
    CropBoxNode ();
    virtual ~CropBoxNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    CropBoxThread thread;
};

#endif
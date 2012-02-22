#ifndef __HOUGH_3D_NODE_H__
#define __HOUGH_3D_NODE_H__

#include "../../GraphEditor/Node.h"
#include <libcloud/Common/PointCloud.h>
#include <libcloud/Filters/HoughFilter.h>

class Hough3dNode : public Node {
  class Hough3dThread : public NodeThread {
    public:
      Hough3dThread (Node* parent = 0);
      virtual ~Hough3dThread ();

      void run ();

      HoughFilter filter;
      PointCloud* input;
      PointCloud output;
  };

  public:
    Hough3dNode ();
    virtual ~Hough3dNode ();

    void preProcess ();
    void process ();
    void postProcess ();

  protected:
    Hough3dThread thread;
};

#endif
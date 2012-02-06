#include "ViewerNode.h"

#include <QMainWindow>
#include "../Viewers/ImageViewerWidget.h"
#include "../Viewers/PointCloudViewerWidget.h"

ViewerNode::ViewerNode ()
  :Node("Viewer")
{
  addInputAnchor ("image");
}

ViewerNode::~ViewerNode ()
{
}

void
ViewerNode::process ()
{
  setRunning ();
  QWidget* viewer;
  // FIXME
  if (QString (inputs["image"]->var->typeName ()) == "Image*") {
    Image* image = inputs["image"]->var->value<Image*> ();
    viewer = new ImageViewerWidget ();
    ((ImageViewerWidget*) viewer)->setImage (image);
  }
  else if (QString (inputs["image"]->var->typeName ()) == "Matrix<UInt8>*"){
    Matrix<UInt8>* image = inputs["image"]->var->value<Matrix<UInt8>*> ();
    viewer = new ImageViewerWidget ();
    ((ImageViewerWidget*) viewer)->setMatrix (image);
  }
  else if (QString (inputs["image"]->var->typeName ()) == "PointCloud*") {
    PointCloud* cloud = inputs["image"]->var->value<PointCloud*> ();
    viewer = new PointCloudViewerWidget ();
    ((PointCloudViewerWidget*) viewer)->addPointCloud ("main", cloud);
  }
  viewer->show ();
  postProcess ();
  unsetRunning ();
}
#include "ViewerNode.h"

#include <QMainWindow>
#include "../Viewers/ImageViewerWidget.h"

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
  ImageViewerWidget* viewer = new ImageViewerWidget ();
  // FIXME
  if (QString (inputs["image"]->var->typeName ()) == QString ("Image*")) {
    Image* image = inputs["image"]->var->value<Image*> ();
    viewer->setImage (image);
  }
  else {
    Matrix<UInt8>* image = inputs["image"]->var->value<Matrix<UInt8>*> ();
    viewer->setMatrix (image);
  }
  viewer->show ();
  postProcess ();
  unsetRunning ();
}
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
  Image* image = inputs["image"]->var->value<Image*> ();
  viewer->setImage (image);
  viewer->show ();
  postProcess ();
  unsetRunning ();
}
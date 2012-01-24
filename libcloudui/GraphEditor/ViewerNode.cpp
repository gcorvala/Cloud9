#include "ViewerNode.h"

#include <QMainWindow>
#include "../ImageViewer.h"

ViewerNode::ViewerNode ()
  :Node("Viewer")
{
  addInputAnchor (new InputAnchor (this), "image");
}

ViewerNode::~ViewerNode ()
{
}

void
ViewerNode::process ()
{
  setRunning ();
  image = inputs["image"]->var->value<Matrix<UInt8>*> ();
  ImageViewer* w = new ImageViewer ();
  w->test = image;
  w->show ();
  endProcess ();
  unsetRunning ();
}
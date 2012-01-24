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

Q_DECLARE_METATYPE (Matrix<UInt8>*);

void
ViewerNode::process ()
{
  setRunning ();
  qDebug ("ViewerNode::process start");
  image = inputs["image"]->var.value<Matrix<UInt8>*> ();
  ImageViewer* w = new ImageViewer ();
  w->test = image;
  w->show ();
  qDebug ("ViewerNode::process end");
  endProcess ();
  unsetRunning ();
}
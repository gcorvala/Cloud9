#include "OutputAnchor.h"

#include "Edge.h"
#include "Graph.h"
#include <QGraphicsSceneDragDropEvent>

OutputAnchor::OutputAnchor (QGraphicsItem* parent)
  :Anchor(parent)
{
}

OutputAnchor::~OutputAnchor ()
{
}

void
OutputAnchor::mousePressEvent (QGraphicsSceneMouseEvent* event)
{
  qDebug ("OutputAnchor::mousePressEvent");

  Graph* graph = (Graph*) scene ();
  graph->drawEdgeFromOutputAnchor (this);
}
#include "InputAnchor.h"

#include "Edge.h"
#include "Graph.h"
#include <QGraphicsSceneDragDropEvent>

InputAnchor::InputAnchor (QGraphicsItem* parent)
  :Anchor(parent)
{
}

InputAnchor::~InputAnchor ()
{
}

void
InputAnchor::mousePressEvent (QGraphicsSceneMouseEvent* event)
{
  qDebug ("InputAnchor::mousePressEvent");

  Graph* graph = (Graph*) scene ();
  graph->drawEdgeFromInputAnchor (this);
}
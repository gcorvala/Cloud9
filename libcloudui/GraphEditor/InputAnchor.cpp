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
InputAnchor::setEdge (Edge* _edge)
{
  Anchor::setEdge (_edge);

  connect (edge, SIGNAL (inputReady ()), this, SIGNAL (inputReady ()));
}

void
InputAnchor::mousePressEvent (QGraphicsSceneMouseEvent* event)
{
  Edge* edge;
  Graph* graph = (Graph*) scene ();

  if (graph->isDrawingEdgeFromOutputAnchor ()) {
    edge = graph->getDrawingEdge ();
    edge->setDestination (*this);
    graph->setDrawingEdgeFromOutputAnchor (false);
  }
  else if (!graph->isDrawingEdgeFromInputAnchor ()) {
    graph->drawEdgeFromInputAnchor (this);
  }
}
#include "InputAnchor.h"

#include "Edge.h"
#include "Graph.h"
#include <QGraphicsSceneDragDropEvent>

InputAnchor::InputAnchor (QGraphicsItem* parent)
  :Anchor(parent)
  ,ready(false)
{
}

InputAnchor::~InputAnchor ()
{
}

bool
InputAnchor::isReady () const
{
  return ready;
}

void
InputAnchor::setEdge (Edge* _edge)
{
  Anchor::setEdge (_edge);

  connect (edge, SIGNAL (inputReady ()), this, SLOT (edgeIsReady ()));
}

void
InputAnchor::edgeIsReady ()
{
  ready = true;
  var = &(edge->getSource ()->var);
  emit inputReady ();
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
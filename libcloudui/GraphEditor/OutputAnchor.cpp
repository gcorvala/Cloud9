#include "OutputAnchor.h"

#include "Edge.h"
#include "Graph.h"
#include <QGraphicsSceneDragDropEvent>

OutputAnchor::OutputAnchor (QGraphicsItem* parent)
  :Anchor(parent)
{
  connect ((QGraphicsWidget*) parent, SIGNAL (processFinished ()), this, SIGNAL (outputReady ()));
}

OutputAnchor::~OutputAnchor ()
{
}

void
OutputAnchor::mousePressEvent (QGraphicsSceneMouseEvent* event)
{
  Edge* edge;
  Graph* graph = (Graph*) scene ();

  if (graph->isDrawingEdgeFromInputAnchor ()) {
    edge = graph->getDrawingEdge ();
    edge->setSource (*this);
    graph->setDrawingEdgeFromInputAnchor (false);
  }
  else if (!graph->isDrawingEdgeFromOutputAnchor ()) {
    graph->drawEdgeFromOutputAnchor (this);
  }
}
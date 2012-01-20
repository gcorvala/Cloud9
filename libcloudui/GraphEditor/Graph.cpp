#include "Graph.h"

#include "Node.h"
#include <QGraphicsSceneMouseEvent>

Graph::Graph ()
  :background_color(239, 236, 202)
  ,drawing_edge_from_input_anchor(false)
  ,drawing_edge_from_output_anchor(false)
{
  setBackgroundBrush (QBrush (background_color));
}

Graph::~Graph ()
{
}

void
Graph::drawEdgeFromInputAnchor (InputAnchor* anchor)
{
  qDebug ("Graph::drawEdgeFromInputAnchor");
  drawing_edge_from_input_anchor = true;
  drawing_edge = new Edge (*anchor);
  addItem (drawing_edge);
}

void
Graph::drawEdgeFromOutputAnchor (OutputAnchor* anchor)
{
  qDebug ("Graph::drawEdgeFromOutputAnchor");
  drawing_edge_from_output_anchor = true;
  drawing_edge = new Edge (*anchor);
  addItem (drawing_edge);
}

bool
Graph::isDrawingEdgeFromInputAnchor () const
{
  return drawing_edge_from_input_anchor;
}

bool
Graph::isDrawingEdgeFromOutputAnchor () const
{
  return drawing_edge_from_output_anchor;
}

void
Graph::addNode ()
{
  Node* node_a = new Node ("Node");
  node_a->setPos (0, 0);
  addItem (node_a);
}

void
Graph::mouseMoveEvent (QGraphicsSceneMouseEvent* mouseEvent)
{
  if (drawing_edge_from_input_anchor) {
    qDebug ("drawing edge from input anchor");
    drawing_edge->setSourcePoint (mouseEvent->scenePos ());
  }
  else if (drawing_edge_from_output_anchor) {
    qDebug ("drawing edge from output anchor");
    drawing_edge->setDestinationPoint (mouseEvent->scenePos ());
  }
  QGraphicsScene::mouseMoveEvent (mouseEvent);
}

void
Graph::mouseReleaseEvent (QGraphicsSceneMouseEvent* mouseEvent)
{
  if (drawing_edge_from_input_anchor || drawing_edge_from_output_anchor) {
    drawing_edge_from_input_anchor = drawing_edge_from_output_anchor = false;
    delete drawing_edge;
  }
  QGraphicsScene::mouseReleaseEvent (mouseEvent);
}
#include "Graph.h"

#include "Node.h"
#include <QGraphicsSceneMouseEvent>

Graph::Graph ()
  :background_color(255, 255, 255)
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
  drawing_edge_from_input_anchor = true;
  drawing_edge = new Edge (*anchor);
  addItem (drawing_edge);
}

void
Graph::drawEdgeFromOutputAnchor (OutputAnchor* anchor)
{
  drawing_edge_from_output_anchor = true;
  drawing_edge = new Edge (*anchor);
  addItem (drawing_edge);
}

bool
Graph::isDrawingEdge () const
{
  return drawing_edge_from_input_anchor | drawing_edge_from_output_anchor;
}

bool
Graph::isDrawingEdgeFromInputAnchor () const
{
  return drawing_edge_from_input_anchor;
}

void
Graph::setDrawingEdgeFromInputAnchor (bool b)
{
  drawing_edge_from_input_anchor = b;
}

bool
Graph::isDrawingEdgeFromOutputAnchor () const
{
  return drawing_edge_from_output_anchor;
}

void
Graph::setDrawingEdgeFromOutputAnchor (bool b)
{
  drawing_edge_from_output_anchor = b;
}

Edge*
Graph::getDrawingEdge () const
{
  return drawing_edge;
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
    drawing_edge->setSourcePoint (mouseEvent->scenePos ());
  }
  else if (drawing_edge_from_output_anchor) {
    drawing_edge->setDestinationPoint (mouseEvent->scenePos ());
  }
  QGraphicsScene::mouseMoveEvent (mouseEvent);
}

void
Graph::mousePressEvent (QGraphicsSceneMouseEvent* event)
{
  bool before = isDrawingEdge ();
  QGraphicsScene::mousePressEvent (event);
  if (before && isDrawingEdge ()) {
    drawing_edge_from_input_anchor = drawing_edge_from_output_anchor = false;
    delete drawing_edge;
  }
}
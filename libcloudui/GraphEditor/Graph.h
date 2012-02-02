#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Edge.h"
#include "Node.h"
#include "InputAnchor.h"
#include "OutputAnchor.h"
#include <QGraphicsScene>

class Graph : public QGraphicsScene {
  Q_OBJECT

  public:
    Graph ();
    virtual ~Graph ();
    void drawEdgeFromInputAnchor (InputAnchor* anchor);
    void drawEdgeFromOutputAnchor (OutputAnchor* anchor);
    bool isDrawingEdge () const;
    bool isDrawingEdgeFromInputAnchor () const;
    void setDrawingEdgeFromInputAnchor (bool b);
    bool isDrawingEdgeFromOutputAnchor () const;
    void setDrawingEdgeFromOutputAnchor (bool b);
    Edge* getDrawingEdge () const;

  public slots:
    void addNode (Node* node);

  signals:
    void nodeSelectedEvent (Node* node);

  protected:
    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent* mouseEvent);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent* event);

  private:
    QColor background_color;
    Edge* drawing_edge;
    bool drawing_edge_from_input_anchor;
    bool drawing_edge_from_output_anchor;
};

#endif
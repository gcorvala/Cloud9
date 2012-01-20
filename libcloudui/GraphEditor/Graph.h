#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Edge.h"
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
    bool isDrawingEdgeFromInputAnchor () const;
    bool isDrawingEdgeFromOutputAnchor () const;

  public slots:
    void addNode ();

  signals:

  protected:
    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent* mouseEvent);
    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent* mouseEvent);

  private:
    QColor background_color;
    Edge *drawing_edge;
    bool drawing_edge_from_input_anchor;
    bool drawing_edge_from_output_anchor;
};

#endif
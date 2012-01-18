#ifndef __EDGE_H__
#define __EDGE_H__

#include <QGraphicsWidget>
#include <QPainter>
#include "Node.h"

class Edge : public QGraphicsWidget {
  Q_OBJECT

  public:
    Edge (Node& _source, Node& _sink);
    virtual ~Edge ();

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect () const;

  public slots:
    void nodePosChanged ();
  signals:

  protected:
    Node *source;
    Node *sink;

    QPen pen;
};

#endif
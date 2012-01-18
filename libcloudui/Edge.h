#ifndef __EDGE_H__
#define __EDGE_H__

#include "Anchor.h"

#include <QGraphicsWidget>
#include <QPainter>

class Edge : public QGraphicsWidget {
  Q_OBJECT

  public:
    Edge (Anchor& _source, Anchor& _sink);
    virtual ~Edge ();

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect () const;

  public slots:
    void anchorPosChanged ();
  signals:

  protected:
    Anchor *source;
    Anchor *sink;

    QPen pen;
};

#endif
#ifndef __ANCHOR_H__
#define __ANCHOR_H__

//#include "Edge.h"
#include <QGraphicsWidget>
#include <QPainter>

class Anchor : public QGraphicsWidget {
  Q_OBJECT

  public:
    Anchor (QGraphicsItem* parent = 0);
    virtual ~Anchor ();

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect () const;
    QPainterPath shape () const;

  public slots:

  signals:
    void scenePositionChanged ();

  protected:
    QVariant itemChange (GraphicsItemChange change, const QVariant& value);
    virtual void hoverEnterEvent (QGraphicsSceneHoverEvent* event);
    virtual void hoverLeaveEvent (QGraphicsSceneHoverEvent* event);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent* event) = 0;

  private:
    qreal radius;
    QPen pen;
    QColor background_color;
    QColor border_color;
    QColor hover_color;
    //Edge* edge;
};

#endif
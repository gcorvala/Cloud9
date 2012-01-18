#ifndef __ANCHOR_H__
#define __ANCHOR_H__

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
    void posChanged ();

  protected:
    void hoverEnterEvent (QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent (QGraphicsSceneHoverEvent* event);

  private:
    qreal radius;
    QPen pen;
    QColor background_color;
    QColor border_color;
    QColor hover_color;
};

#endif
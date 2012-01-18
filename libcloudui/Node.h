#ifndef __NODE_H__
#define __NODE_H__

#include <QGraphicsWidget>
#include <QPainter>

class Node : public QGraphicsWidget {
  Q_OBJECT

  public:
    Node (const QString& title);
    virtual ~Node ();

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect () const;
    QPainterPath shape () const;

  public slots:

  signals:
    void posChanged ();

  protected:
    void moveEvent (QGraphicsSceneMoveEvent* event);

  private:
    QGraphicsSimpleTextItem title;
    qreal height;
    qreal width;
    qreal x_radius;
    qreal y_radius;
    QPen pen;
    QColor background_color;
};

#endif
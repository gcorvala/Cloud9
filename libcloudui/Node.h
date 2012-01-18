#ifndef __NODE_H__
#define __NODE_H__

#include "Anchor.h"

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

    void addInputAnchor (const Anchor& input);
    void removeInputAnchor (const Anchor& input);

    void addOutputAnchor (const Anchor& input);
    void removeOutputAnchor (const Anchor& input);

    QList<Anchor*>& getInputAnchors ();
    QList<Anchor*>& getOutputAnchors ();

  public slots:

  signals:
    void posChanged ();

  protected:
    void moveEvent (QGraphicsSceneMoveEvent* event);
    void hoverEnterEvent (QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent (QGraphicsSceneHoverEvent* event);
    void placeAnchors ();

  private:
    QGraphicsSimpleTextItem title;
    qreal height;
    qreal width;
    qreal x_radius;
    qreal y_radius;
    QPen pen;
    QColor background_color;
    QColor border_color;
    QList<Anchor*> input_anchors;
    QList<Anchor*> output_anchors;
};

#endif
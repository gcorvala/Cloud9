#ifndef __NODE_H__
#define __NODE_H__

#include "InputAnchor.h"
#include "OutputAnchor.h"

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

    void addInputAnchor (const InputAnchor& input);
    void removeInputAnchor (const InputAnchor& input);

    void addOutputAnchor (const OutputAnchor& output);
    void removeOutputAnchor (const OutputAnchor& output);

    QList<InputAnchor*>& getInputAnchors ();
    QList<OutputAnchor*>& getOutputAnchors ();

  public slots:

  signals:
    void posChanged ();

  protected:
    virtual void moveEvent (QGraphicsSceneMoveEvent* event);
    virtual void hoverEnterEvent (QGraphicsSceneHoverEvent* event);
    virtual void hoverLeaveEvent (QGraphicsSceneHoverEvent* event);
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
    QList<InputAnchor*> input_anchors;
    QList<OutputAnchor*> output_anchors;
};

#endif
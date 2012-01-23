#ifndef __NODE_H__
#define __NODE_H__

#include "InputAnchor.h"
#include "OutputAnchor.h"
#include "NodeThread.h"

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

    void addInputAnchor (InputAnchor* input);
    void addOutputAnchor (OutputAnchor* output);

    QList<InputAnchor*>& getInputAnchors ();
    QList<OutputAnchor*>& getOutputAnchors ();

    void startProcess ();

  public slots:
    virtual void endProcess ();
    void tryToStartProcess ();
    void setRunning ();
    void unsetRunning ();

  signals:
    void posChanged ();
    void processFinished ();

  protected:
    virtual void moveEvent (QGraphicsSceneMoveEvent* event);
    virtual void mouseDoubleClickEvent (QGraphicsSceneMouseEvent* event);
    void placeAnchors ();
    void setNodeThread (NodeThread* ptr);

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
    NodeThread* thread;
    bool running;
};

#endif
#ifndef __NODE_H__
#define __NODE_H__

#include "InputAnchor.h"
#include "OutputAnchor.h"
#include "NodeThread.h"

#include <QGraphicsWidget>
#include <QPainter>
#include <QString>

class Node : public QGraphicsWidget {
  Q_OBJECT

  public:
    Node (const QString& title);
    virtual ~Node ();

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect () const;
    QPainterPath shape () const;

    void addInputAnchor (const QString& key, InputAnchor* input);
    void addOutputAnchor (const QString& key, OutputAnchor* output);

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
    QMap<QString, InputAnchor*> inputs;
    QMap<QString, OutputAnchor*> outputs;
    NodeThread* thread;
    bool running;
};

#endif
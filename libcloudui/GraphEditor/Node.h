#ifndef __NODE_H__
#define __NODE_H__

#include "InputAnchor.h"
#include "OutputAnchor.h"
#include "MetaTypes.h"

#include <QGraphicsWidget>
#include <QThread>
#include <QPainter>
#include <QString>

class Node : public QGraphicsWidget {
  Q_OBJECT
  protected:
    class NodeThread : public QThread {
      public:
        NodeThread (Node* parent);
        virtual ~NodeThread ();

        void run () = 0;
    };
  public:
    Node (const QString& title);
    virtual ~Node ();

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect () const;
    QPainterPath shape () const;

    void addInputAnchor (const QString& key);
    void addOutputAnchor (const QString& key);

    virtual void preProcess ();
    virtual void process () = 0;

  public slots:
    void startProcess ();
    virtual void postProcess ();

    void setRunning ();
    void unsetRunning ();

  signals:
    void posChanged ();
    void processFinished ();

  protected:
    virtual void moveEvent (QGraphicsSceneMoveEvent* event);
    virtual void mouseDoubleClickEvent (QGraphicsSceneMouseEvent* event);
    void placeAnchors ();

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
    bool running;
};

#endif
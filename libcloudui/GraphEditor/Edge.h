#ifndef __EDGE_H__
#define __EDGE_H__

#include "InputAnchor.h"
#include "OutputAnchor.h"

#include <QGraphicsWidget>
#include <QPainter>

class Edge : public QGraphicsWidget {
  Q_OBJECT

  public:
    Edge (InputAnchor& dst);
    Edge (OutputAnchor& src);
    Edge (OutputAnchor& src, InputAnchor& dst);
    virtual ~Edge ();

    void init ();

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect () const;

    void setSource (OutputAnchor& src);
    void setDestination (InputAnchor& dst);
    void setSourcePoint (const QPointF p);
    void setDestinationPoint (const QPointF p);

  public slots:
    void anchorPosChanged ();

  signals:
    void inputReady ();

  protected:
    QPointF source_point;
    QPointF destination_point;
    OutputAnchor *source;
    InputAnchor *destination;
    bool locked;

    QPen pen;
};

#endif
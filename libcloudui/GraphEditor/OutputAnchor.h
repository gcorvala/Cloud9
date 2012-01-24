#ifndef __OUTPUT_ANCHOR_H__
#define __OUTPUT_ANCHOR_H__

#include "Anchor.h"
#include <QVariant>

class OutputAnchor : public Anchor {
  Q_OBJECT

  public:
    OutputAnchor (QGraphicsItem* parent);
    virtual ~OutputAnchor ();

  public slots:

  signals:
    void outputReady ();

  protected:
    virtual void mousePressEvent (QGraphicsSceneMouseEvent* event);
  public:
    QVariant var;
};

#endif
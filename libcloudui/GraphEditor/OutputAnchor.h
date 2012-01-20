#ifndef __OUTPUT_ANCHOR_H__
#define __OUTPUT_ANCHOR_H__

#include "Anchor.h"

class OutputAnchor : public Anchor {
  Q_OBJECT

  public:
    OutputAnchor (QGraphicsItem* parent = 0);
    virtual ~OutputAnchor ();

  public slots:

  signals:

  protected:
    virtual void mousePressEvent (QGraphicsSceneMouseEvent* event);

  private:

};

#endif
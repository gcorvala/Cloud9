#ifndef __INPUT_ANCHOR_H__
#define __INPUT_ANCHOR_H__

#include "Anchor.h"

class InputAnchor : public Anchor {
  Q_OBJECT

  public:
    InputAnchor (QGraphicsItem* parent = 0);
    virtual ~InputAnchor ();

    void setEdge (Edge* _edge);
    bool isReady () const;

  public slots:
    void edgeIsReady ();

  signals:
    void inputReady ();

  protected:
    virtual void mousePressEvent (QGraphicsSceneMouseEvent* event);

  private:
    bool ready;
};

#endif
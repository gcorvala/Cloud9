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

    template<typename T>
    T getValue ();

  public slots:
    void edgeIsReady ();

  signals:
    void inputReady ();

  protected:
    virtual void mousePressEvent (QGraphicsSceneMouseEvent* event);

  private:
    bool ready;
  // FIXME
  public:
    QVariant* var;
};

template<typename T>
T
InputAnchor::getValue ()
{
  qDebug ("InputAnchor::typename %s", var->typeName ());
  return var->value<T> ();
}

#endif
#ifndef __OUTPUT_ANCHOR_H__
#define __OUTPUT_ANCHOR_H__

#include "Anchor.h"
#include <QVariant>

class OutputAnchor : public Anchor {
  Q_OBJECT

  public:
    OutputAnchor (QGraphicsItem* parent);
    virtual ~OutputAnchor ();

    template<typename T>
    void setValue (T v);

  public slots:

  signals:
    void outputReady ();

  protected:
    virtual void mousePressEvent (QGraphicsSceneMouseEvent* event);
  // FIXME
  public:
    QVariant var;
};

template<typename T>
void
OutputAnchor::setValue (T v)
{
  qDebug ("OutputAnchor::typename %s", var.typeName ());
  var.setValue (v);
}

#endif
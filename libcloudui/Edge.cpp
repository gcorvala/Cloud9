#include "Edge.h"
#include <iostream>
Edge::Edge (Node& _source, Node& _sink)
  :source(&_source)
  ,sink(&_sink)
{
  setFlag (QGraphicsItem::ItemSendsGeometryChanges);
  setFlag (QGraphicsItem::ItemSendsScenePositionChanges);

  QObject::connect (source, SIGNAL (posChanged ()), this, SLOT (nodePosChanged ()));
  QObject::connect (sink, SIGNAL (posChanged ()), this, SLOT (nodePosChanged ()));

  pen.setWidth (10);
  pen.setColor (QColor (145, 170, 157));
}

Edge::~Edge ()
{
}

void
Edge::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  painter->setPen (pen);

  painter->drawLine (source->pos (), sink->pos ());
}

QRectF
Edge::boundingRect () const
{
  return QRectF (source->pos (), QSizeF (sink->pos ().x ()-source->pos ().x (), sink->pos ().y ()-source->pos ().y ())).normalized ().adjusted (-pen.width ()/2, -pen.width ()/2, pen.width ()/2, pen.width ()/2);
}

void
Edge::nodePosChanged ()
{
  prepareGeometryChange ();
}

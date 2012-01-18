#include "Edge.h"

Edge::Edge (Anchor& _source, Anchor& _sink)
  :source(&_source)
  ,sink(&_sink)
{
  setFlag (QGraphicsItem::ItemSendsGeometryChanges);
  setFlag (QGraphicsItem::ItemSendsScenePositionChanges);

  QObject::connect (source->parentObject (), SIGNAL (posChanged ()), this, SLOT (anchorPosChanged ()));
  QObject::connect (sink->parentObject (), SIGNAL (posChanged ()), this, SLOT (anchorPosChanged ()));

  pen.setWidth (5);
  pen.setColor (QColor (0, 47, 47));
}

Edge::~Edge ()
{
}

void
Edge::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  painter->setPen (pen);

  painter->drawLine (source->scenePos (), sink->scenePos ());
}

QRectF
Edge::boundingRect () const
{
  return QRectF (source->scenePos (), QSizeF (sink->scenePos ().x ()-source->scenePos ().x (), sink->scenePos ().y ()-source->scenePos ().y ())).normalized ().adjusted (-pen.width ()/2, -pen.width ()/2, pen.width ()/2, pen.width ()/2);
}

void
Edge::anchorPosChanged ()
{
  qDebug ("Edge::anchorPosChanged");
  prepareGeometryChange ();
}

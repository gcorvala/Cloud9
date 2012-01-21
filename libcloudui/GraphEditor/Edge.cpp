#include "Edge.h"

Edge::Edge (InputAnchor& dst)
  :source(NULL)
  ,destination(&dst)
  ,source_point(dst.scenePos ())
  ,destination_point(dst.scenePos ())
{
  init ();
  QObject::connect (destination, SIGNAL (scenePositionChanged ()), this, SLOT (anchorPosChanged ()));
}

Edge::Edge (OutputAnchor& src)
  :source(&src)
  ,destination(NULL)
  ,source_point(src.scenePos ())
  ,destination_point(src.scenePos ())
{
  init ();
  QObject::connect (source, SIGNAL (scenePositionChanged ()), this, SLOT (anchorPosChanged ()));
}

Edge::Edge (OutputAnchor& src, InputAnchor& dst)
  :source(&src)
  ,destination(&dst)
  ,source_point(src.scenePos ())
  ,destination_point(dst.scenePos ())
{
  init ();

  QObject::connect (source, SIGNAL (scenePositionChanged ()), this, SLOT (anchorPosChanged ()));
  QObject::connect (destination, SIGNAL (scenePositionChanged ()), this, SLOT (anchorPosChanged ()));
}

Edge::~Edge ()
{
}

void
Edge::init ()
{
  setFlag (QGraphicsItem::ItemSendsGeometryChanges);
  setFlag (QGraphicsItem::ItemSendsScenePositionChanges);

  pen.setWidth (5);
  pen.setColor (QColor (255, 152, 0));
}

void
Edge::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  painter->setPen (pen);

  painter->drawLine (source_point, destination_point);
}

QRectF
Edge::boundingRect () const
{
  return QRectF (source_point, QSizeF (destination_point.x ()-source_point.x (), destination_point.y ()-source_point.y ())).normalized ().adjusted (-pen.width ()/2, -pen.width ()/2, pen.width ()/2, pen.width ()/2);
}

void
Edge::setSource (OutputAnchor& src)
{
  source = &src;
  QObject::connect (source, SIGNAL (scenePositionChanged ()), this, SLOT (anchorPosChanged ()));
  prepareGeometryChange ();
}

void
Edge::setDestination (InputAnchor& dst)
{
  prepareGeometryChange ();
  destination = &dst;
  QObject::connect (destination, SIGNAL (scenePositionChanged ()), this, SLOT (anchorPosChanged ()));
}

void
Edge::setSourcePoint (const QPointF p)
{
  prepareGeometryChange ();
  source_point = p;
}

void
Edge::setDestinationPoint (const QPointF p)
{
  prepareGeometryChange ();
  destination_point = p;
}

void
Edge::anchorPosChanged ()
{
  prepareGeometryChange ();
  source_point = source->scenePos ();
  destination_point = destination->scenePos ();
}
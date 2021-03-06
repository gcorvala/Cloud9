#include "Anchor.h"

#include "Graph.h"
#include <QGraphicsSceneMouseEvent>

Anchor::Anchor (QGraphicsItem* parent)
  :QGraphicsWidget(parent)
  ,background_color(255, 132, 0)
  ,hover_color(0, 255, 0)
  ,border_color(38, 50, 72)
  ,radius(8)
  ,edge(NULL)
{
  setFlag (QGraphicsItem::ItemSendsGeometryChanges);
  setFlag (QGraphicsItem::ItemSendsScenePositionChanges);

  setAcceptHoverEvents (true);
  setAcceptDrops (true);

  pen.setWidth (2);
  pen.setColor (border_color);

  setZValue (1);
}

Anchor::~Anchor ()
{
}

void
Anchor::setEdge (Edge* _edge)
{
  edge = _edge;
}

Edge*
Anchor::getEdge () const
{
  return edge;
}

void
Anchor::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  QPainterPath path;

  painter->setPen (pen);

  path.addEllipse (-radius/2, -radius/2, radius, radius);

  painter->fillPath (path, QBrush (background_color));
  painter->drawPath (path);
}

QRectF
Anchor::boundingRect () const
{
  return QRectF (-radius/2, -radius/2, radius, radius).normalized ().adjusted (-pen.width ()/2, -pen.width ()/2, pen.width ()/2, pen.width ()/2);
}

QPainterPath
Anchor::shape () const
{
  QPainterPath path;

  path.addEllipse (-radius/2, -radius/2, radius, radius);

  return path;
}

QVariant
Anchor::itemChange (GraphicsItemChange change, const QVariant& value)
{
  if (change == QGraphicsItem::ItemScenePositionHasChanged) {
    emit scenePositionChanged ();
  }
  return value;
}

void
Anchor::hoverEnterEvent (QGraphicsSceneHoverEvent* event)
{
  background_color = hover_color;
  update ();
}

void
Anchor::hoverLeaveEvent (QGraphicsSceneHoverEvent* event)
{
  background_color = QColor (255, 132, 0);
  update ();
}
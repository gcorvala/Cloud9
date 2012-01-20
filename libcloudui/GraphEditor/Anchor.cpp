#include "Anchor.h"

#include "Graph.h"
#include <QGraphicsSceneMouseEvent>

Anchor::Anchor (QGraphicsItem* parent)
  :QGraphicsWidget(parent)
  ,background_color(230, 226, 175)
  ,hover_color(0, 47, 47)
  ,border_color(0, 47, 47)
  ,radius(8)
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
    qDebug ("Anchor::itemScenePositionHasChanged");
    emit scenePositionChanged ();
  }
  return value;
}

void
Anchor::hoverEnterEvent (QGraphicsSceneHoverEvent* event)
{
  qDebug ("Anchor::hoverEnterEvent");
  background_color = QColor (255, 0, 0);
  update ();
}

void
Anchor::hoverLeaveEvent (QGraphicsSceneHoverEvent* event)
{
  qDebug ("Anchor::hoverLeaveEvent");
  background_color = QColor (209, 219, 189);
  update ();
}

void
Anchor::mouseReleaseEvent (QGraphicsSceneMouseEvent* event)
{
  Graph* graph = (Graph*) scene ();
}
#include "Node.h"

#include <QProgressBar>
#include <iostream>

Node::Node (const QString& _title)
  :title(_title, this)
  ,background_color(209, 219, 189)
  ,height(60)
  ,width(100)
  ,x_radius(15)
  ,y_radius(10)
{
  setFlag (QGraphicsItem::ItemIsMovable);
  setFlag (QGraphicsItem::ItemIsFocusable);
  setFlag (QGraphicsItem::ItemIsSelectable);
  setFlag (QGraphicsItem::ItemSendsGeometryChanges);
  setFlag (QGraphicsItem::ItemSendsScenePositionChanges);

  pen.setWidth (10);
  pen.setColor (QColor (62, 96, 111));

  QRectF w = title.boundingRect ();
  title.setPos (-w.width ()/2, -height/2+10);
  setZValue (+1);
}

Node::~Node ()
{
}

void
Node::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  QPainterPath path;

  painter->setPen (pen);

  path.addRoundedRect (-width/2, -height/2, width, height, x_radius, y_radius);

  painter->fillPath (path, QBrush (background_color));
  painter->drawPath (path);
}

QRectF
Node::boundingRect () const
{
  return QRectF (-width/2, -height/2, width, height).normalized ().adjusted (-pen.width ()/2, -pen.width ()/2, pen.width ()/2, pen.width ()/2);
}

QPainterPath
Node::shape () const
{
  QPainterPath path;

  path.addRoundedRect (boundingRect (), x_radius, y_radius);

  return path;
}

void
Node::moveEvent (QGraphicsSceneMoveEvent* event)
{
  emit posChanged ();
}
#include "Node.h"

#include "Anchor.h"
//#include "NullThread.h"
#include <QProgressBar>
#include <iostream>
#include <libcloud/2D/Matrix.h>

Node::Node (const QString& _title)
  :title(_title, this)
  ,background_color(126, 138, 162)
  ,border_color(38, 50, 72)
  ,height(60)
  ,width(100)
  ,x_radius(15)
  ,y_radius(10)
//  ,thread(NULL)
{
  setFlag (QGraphicsItem::ItemIsMovable);
  setFlag (QGraphicsItem::ItemSendsGeometryChanges);
  setFlag (QGraphicsItem::ItemSendsScenePositionChanges);

  setAcceptHoverEvents (true);

  pen.setWidth (5);
  pen.setColor (border_color);

  QRectF w = title.boundingRect ();
  title.setPos (-w.width ()/2, -height/2+10);

  setZValue (1);

//  setNodeThread (new NullThread ());
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
Node::addInputAnchor (InputAnchor* input, const QString& key)
{
  inputs[key] = input;
  connect (input, SIGNAL (inputReady ()), this, SLOT (startProcess ()));
  placeAnchors ();
}

void
Node::addOutputAnchor (OutputAnchor* output, const QString& key)
{
  outputs[key] = output;
  placeAnchors ();
}

void
Node::startProcess ()
{
  InputAnchor* input;
  bool ready = true;

  foreach (input, inputs) {
    if (!input->isReady ()) {
      ready = false;
    }
  }
  if (ready) {
    process ();
  }
}

void
Node::endProcess ()
{
  
}

void
Node::moveEvent (QGraphicsSceneMoveEvent* event)
{
  emit posChanged ();
}

void
Node::mouseDoubleClickEvent (QGraphicsSceneMouseEvent* event)
{
  startProcess ();
}

void
Node::placeAnchors ()
{
  InputAnchor *input;
  OutputAnchor *output;
  quint32 nb = inputs.size ();
  qreal h = height-2*y_radius;
  qreal h_step = h/(nb+1);
  qreal pos = y_radius+h_step;

  foreach (input, inputs) {
    input->setX (-width/2);
    input->setY (-height/2+pos);
    pos += h_step;
  }

  nb = outputs.size ();
  h_step = h/(nb+1);
  pos = y_radius+h_step;

  foreach (output, outputs) {
    output->setX (width/2);
    output->setY (-height/2+pos);
    pos += h_step;
  }
}

/*void
Node::setNodeThread (NodeThread* ptr)
{
  thread = ptr;
  connect (thread, SIGNAL (started ()), this, SLOT (setRunning ()));
  connect (thread, SIGNAL (finished ()), this, SLOT (unsetRunning ()));
  connect (thread, SIGNAL (finished ()), this, SLOT (endProcess ()));
}*/

void
Node::setRunning ()
{
  background_color = QColor (255, 0, 0);
  update ();
}

void
Node::unsetRunning ()
{
  background_color = QColor (126, 138, 162);
  update ();
  emit processFinished ();
}
#include "PointCloudViewerWidget.h"

#include <QMouseEvent>
#include "../Actors/PointCloudActor.h"
#include "../Actors/AxisActor.h"

PointCloudViewerWidget::PointCloudViewerWidget (QWidget *parent)
  :QGLWidget(QGLFormat (), parent)
  ,x_rotation(0)
  ,y_rotation(0)
  ,z_rotation(0)
{
  actors.push_back (new AxisActor ());
}

PointCloudViewerWidget::~PointCloudViewerWidget ()
{
}

QSize
PointCloudViewerWidget::minimumSizeHint () const
{
  return QSize (50, 50);
}

QSize
PointCloudViewerWidget::sizeHint () const
{
  return QSize (600, 400);
}


void
PointCloudViewerWidget::addPointCloud (const QString& key, PointCloud* cloud)
{
  actors.push_back (new PointCloudActor (*cloud));

  updateGL ();
}

static void qNormalizeAngle(int &angle)
{
  while (angle < 0)
    angle += 360 * 16;
  while (angle > 360 * 16)
    angle -= 360 * 16;
}

void
PointCloudViewerWidget::setXRotation (int angle)
{
  qNormalizeAngle(angle);
  if (angle != x_rotation) {
    x_rotation = angle;
    updateGL();
  }
}

void
PointCloudViewerWidget::setYRotation (int angle)
{
  qNormalizeAngle(angle);
  if (angle != y_rotation) {
    y_rotation = angle;
    updateGL();
  }
}

void
PointCloudViewerWidget::setZRotation (int angle)
{
  qNormalizeAngle(angle);
  if (angle != z_rotation) {
    z_rotation = angle;
    updateGL();
  }
}

void
PointCloudViewerWidget::initializeGL ()
{
  qglClearColor (Qt::black);
}

void
PointCloudViewerWidget::paintGL ()
{
  std::vector<Actor*>::const_iterator it;
  glClear (GL_COLOR_BUFFER_BIT);
  glLoadIdentity ();

  glRotatef (x_rotation, 1.0, 0.0, 0.0);
  glRotatef (y_rotation, 0.0, 1.0, 0.0);
  glRotatef (z_rotation, 0.0, 0.0, 1.0);

  for (it = actors.begin (); it != actors.end (); ++it) {
    Actor* actor = *it;
    actor->draw ();
  }
}

void
PointCloudViewerWidget::resizeGL (int width, int height)
{
  qDebug ("resizeGL");
  glViewport (0, 0, width, height);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  //glOrtho (-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
  glOrtho (-500.5, +500.5, -500.5, +500.5, -1004.0, 100000.0);
  glMatrixMode (GL_MODELVIEW);
}

void
PointCloudViewerWidget::mousePressEvent (QMouseEvent *event)
{
  last_pos = event->pos();
}

void
PointCloudViewerWidget::mouseMoveEvent (QMouseEvent *event)
{
  int dx = event->x() - last_pos.x();
  int dy = event->y() - last_pos.y();

  if (event->buttons() & Qt::LeftButton) {
    setXRotation (x_rotation + dy);
    setYRotation (y_rotation + dx);
  } else if (event->buttons() & Qt::RightButton) {
    setXRotation (x_rotation + dy);
    setZRotation (z_rotation + dx);
  }
  last_pos = event->pos();
}
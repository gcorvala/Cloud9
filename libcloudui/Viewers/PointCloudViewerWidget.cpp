#include "PointCloudViewerWidget.h"

#include <QMouseEvent>

PointCloudViewerWidget::PointCloudViewerWidget (QWidget *parent)
  :QGLWidget(QGLFormat (), parent)
  ,x_rotation(0)
  ,y_rotation(0)
  ,z_rotation(0)
{
}

PointCloudViewerWidget::~PointCloudViewerWidget ()
{
}

QSize
PointCloudViewerWidget::minimumSizeHint () const
{
  return QSize(50, 50);
}

QSize
PointCloudViewerWidget::sizeHint () const
{
  return QSize (600, 400);
}


void
PointCloudViewerWidget::addPointCloud (const QString& key, PointCloud* cloud)
{
  PointCloud::const_iterator it;

  clouds[key] = cloud;

  for (it = cloud->begin (); it != cloud->end (); ++it) {
    //qDebug ("x:%f x/2300:%f", (*it).x, (*it).x/2300);
    vertex_array.push_back (QVector3D ((*it).x, (*it).y, (*it).z));
  }

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
  glClear (GL_COLOR_BUFFER_BIT);
  glLoadIdentity ();
//  glTranslatef (0.0, -0.1, -10.0);

  glRotatef (x_rotation, 1.0, 0.0, 0.0);
  glRotatef (y_rotation, 0.0, 1.0, 0.0);
  glRotatef (z_rotation, 0.0, 0.0, 1.0);

  qglColor (Qt::green);

  glEnableClientState (GL_VERTEX_ARRAY);
  glVertexPointer (3, GL_FLOAT, 0, vertex_array.constData ());
  glDrawArrays (GL_POINTS, 0, vertex_array.size ());
  glDisableClientState (GL_VERTEX_ARRAY);
}

void
PointCloudViewerWidget::resizeGL (int width, int height)
{
  qDebug ("resizeGL");
  glViewport (0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
  glOrtho(-500.5, +500.5, -500.5, +500.5, 4.0, 2500.0);
  glMatrixMode(GL_MODELVIEW);
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
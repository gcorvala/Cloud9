#include "Viewer3dWidget.h"

#include <QMouseEvent>
#include "../Actors/PointCloudActor.h"
#include "../Actors/AxisActor.h"
#include "../Actors/BoxActor.h"
#include "../Actors/PlaneActor.h"
#include "../Actors/LineActor.h"
#include <math.h>

Viewer3dWidget::Viewer3dWidget (QWidget *parent)
  :QGLWidget(QGLFormat (), parent)
  ,x_rotation(0)
  ,y_rotation(0)
  ,z_rotation(0)
  ,m_zoom_factor(1)
{
  actors.push_back (new AxisActor ());
/*  actors.push_back (new LineActor (Line (100, M_PI/4)));
  actors.push_back (new LineActor (Line (100, M_PI/2)));
  actors.push_back (new LineActor (Line (100, 3*M_PI/4)));
  actors.push_back (new LineActor (Line (100, M_PI)));
  actors.push_back (new LineActor (Line (100, 5*M_PI/4)));
  actors.push_back (new LineActor (Line (100, 3*M_PI/2)));
  actors.push_back (new LineActor (Line (100, 7*M_PI/4)));
  actors.push_back (new LineActor (Line (100, 2*M_PI)));*/
  //actors.push_back (new BoxActor (Point (-100, 50, -100), Point (100, 100, 100)));

  //actors.push_back (new PlaneActor (Plane (650.715, 1.54712, 1.54712)));
}

Viewer3dWidget::~Viewer3dWidget ()
{
}

QSize
Viewer3dWidget::minimumSizeHint () const
{
  return QSize (50, 50);
}

QSize
Viewer3dWidget::sizeHint () const
{
  return QSize (600, 400);
}


void
Viewer3dWidget::add (const QString& key, PointCloud* cloud)
{
  actors.push_back (new PointCloudActor (*cloud));

  updateGL ();
}

void
Viewer3dWidget::add (const QString& key, Plane* plane)
{
  actors.push_back (new PlaneActor (*plane));

  updateGL ();
}

void
Viewer3dWidget::add (const QString& key, Line* line)
{
  actors.push_back (new LineActor (*line));

  updateGL ();
}

void
Viewer3dWidget::add (const Line& line)
{
  actors.push_back (new LineActor (line));

  updateGL ();
  std::cout << "aie" << std::endl;
}

static void qNormalizeAngle(int &angle)
{
  while (angle < 0)
    angle += 360 * 16;
  while (angle > 360 * 16)
    angle -= 360 * 16;
}

void
Viewer3dWidget::setXRotation (int angle)
{
  qNormalizeAngle(angle);
  if (angle != x_rotation) {
    x_rotation = angle;
    updateGL();
  }
}

void
Viewer3dWidget::setYRotation (int angle)
{
  qNormalizeAngle(angle);
  if (angle != y_rotation) {
    y_rotation = angle;
    updateGL();
  }
}

void
Viewer3dWidget::setZRotation (int angle)
{
  qNormalizeAngle(angle);
  if (angle != z_rotation) {
    z_rotation = angle;
    updateGL();
  }
}

void
Viewer3dWidget::initializeGL ()
{
  qglClearColor (Qt::gray);
  glEnable (GL_DEPTH_TEST);
  glEnable (GL_POINT_SMOOTH);
  //glEnable (GL_BLEND);
  //glBlendFunc (GL_ONE, GL_ONE);
  //glEnable (GL_LIGHTING);
}

void
Viewer3dWidget::paintGL ()
{
  std::vector<Actor*>::const_iterator it;

  glClear (GL_COLOR_BUFFER_BIT);
  glClear (GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();

  glTranslated (0.0, 0.0, m_zoom_factor);
  glRotatef (x_rotation, 1.0, 0.0, 0.0);
  glRotatef (y_rotation, 0.0, 1.0, 0.0);
  glRotatef (z_rotation, 0.0, 0.0, 1.0);
  glTranslatef (-1400, -1400, -1400);

  for (it = actors.begin (); it != actors.end (); ++it) {
    Actor* actor = *it;
    actor->draw ();
  }
}

void
Viewer3dWidget::resizeGL (int width, int height)
{
  glViewport (0, 0, width, height);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glOrtho (-500*m_zoom_factor, 500*m_zoom_factor, -500*m_zoom_factor, 500*m_zoom_factor, -100000, 100000);
  glMatrixMode (GL_MODELVIEW);
}

void
Viewer3dWidget::mousePressEvent (QMouseEvent *event)
{
  last_pos = event->pos();
}

void
Viewer3dWidget::mouseMoveEvent (QMouseEvent *event)
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

void
Viewer3dWidget::wheelEvent (QWheelEvent* event)
{
  m_zoom_factor += 0.01*event->delta ();

  resizeGL (width (), height ());

  updateGL ();
}
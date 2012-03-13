#include "BoxActor.h"

#if (CMAKE_SYSTEM_NAME == Linux)
  #include <GL/gl.h>
#else
  #include <gl/GL.h>
#endif

#include "LineActor.h"

#include <iostream>

BoxActor::BoxActor (const Point& min, const Point& max)
  :m_min(min)
  ,m_max(max)
{
  children.push_back (new LineActor (m_min, Point (m_min.x, m_min.y, m_max.z)));
  children.push_back (new LineActor (m_min, Point (m_min.x, m_max.y, m_min.z)));
  children.push_back (new LineActor (m_min, Point (m_max.x, m_min.y, m_min.z)));
  children.push_back (new LineActor (m_max, Point (m_max.x, m_max.y, m_min.z)));
  children.push_back (new LineActor (m_max, Point (m_max.x, m_min.y, m_max.z)));
  children.push_back (new LineActor (m_max, Point (m_min.x, m_max.y, m_max.z)));
  children.push_back (new LineActor (Point (m_min.x, m_min.y, m_max.z), Point (m_min.x, m_max.y, m_max.z)));
  children.push_back (new LineActor (Point (m_min.x, m_min.y, m_max.z), Point (m_max.x, m_min.y, m_max.z)));
  children.push_back (new LineActor (Point (m_min.x, m_max.y, m_min.z), Point (m_min.x, m_max.y, m_max.z)));
  children.push_back (new LineActor (Point (m_min.x, m_max.y, m_min.z), Point (m_max.x, m_max.y, m_min.z)));
  children.push_back (new LineActor (Point (m_max.x, m_min.y, m_min.z), Point (m_max.x, m_max.y, m_min.z)));
  children.push_back (new LineActor (Point (m_max.x, m_min.y, m_min.z), Point (m_max.x, m_min.y, m_max.z)));
}

BoxActor::~BoxActor ()
{
}

void
BoxActor::draw () const
{
  Actor::draw ();
#if 0
  glBegin (GL_QUADS);

  glColor4f (255, 0, 0, 0.5f);

  glVertex3f (m_min.x, m_min.y, m_min.z);
  glVertex3f (m_max.x, m_min.y, m_min.z);
  glVertex3f (m_max.x, m_max.y, m_min.z);
  glVertex3f (m_min.x, m_max.y, m_min.z);

  glVertex3f (m_min.x, m_min.y, m_min.z);
  glVertex3f (m_min.x, m_min.y, m_max.z);
  glVertex3f (m_max.x, m_min.y, m_max.z);
  glVertex3f (m_max.x, m_min.y, m_min.z);

  glVertex3f (m_min.x, m_min.y, m_min.z);
  glVertex3f (m_min.x, m_max.y, m_min.z);
  glVertex3f (m_min.x, m_max.y, m_max.z);
  glVertex3f (m_min.x, m_min.y, m_max.z);

  glVertex3f (m_max.x, m_max.y, m_max.z);
  glVertex3f (m_min.x, m_max.y, m_max.z);
  glVertex3f (m_min.x, m_min.y, m_max.z);
  glVertex3f (m_max.x, m_min.y, m_max.z);

  glVertex3f (m_max.x, m_max.y, m_max.z);
  glVertex3f (m_min.x, m_max.y, m_max.z);
  glVertex3f (m_min.x, m_max.y, m_min.z);
  glVertex3f (m_max.x, m_max.y, m_min.z);

  glVertex3f (m_max.x, m_max.y, m_max.z);
  glVertex3f (m_max.x, m_min.y, m_max.z);
  glVertex3f (m_min.x, m_min.y, m_max.z);
  glVertex3f (m_min.x, m_max.y, m_max.z);

  glEnd ();
#else
  glBegin (GL_LINES);

  glEnd ();
#endif
}

#include "LineActor.h"

#include <gl/GL.h>

LineActor::LineActor (const Point& start, const Point& end)
  :m_start(start)
  ,m_end(end)
{
}

LineActor::~LineActor ()
{
}

void
LineActor::draw () const
{
  glBegin (GL_LINES);

  glColor3ub (255, 0, 0);

  glVertex3f (m_start.x, m_start.y, m_start.z);
  glVertex3f (m_end.x, m_end.y, m_end.z);

  glEnd ();
}
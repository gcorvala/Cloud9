#include "BoxActor.h"

#include <gl/GL.h>

BoxActor::BoxActor (const Point& min, const Point& max)
  :m_min(min)
  ,m_max(max)
{
}

BoxActor::~BoxActor ()
{
}

void
BoxActor::draw () const
{
  glBegin (GL_QUADS);

  glColor4f (255, 0, 0, 50);

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
}
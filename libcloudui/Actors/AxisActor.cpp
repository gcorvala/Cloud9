#include "AxisActor.h"

#include <GL/gl.h>

AxisActor::AxisActor ()
  :m_size(100)
{
}

AxisActor::~AxisActor ()
{
}

void
AxisActor::draw () const
{
  glBegin (GL_LINES);

  glColor3f (255, 0, 0);
	glVertex3f (0, 0, 0);
	glVertex3f (m_size, 0, 0);

	glColor3f (0, 255, 0);
	glVertex3f (0, 0, 0);
	glVertex3f (0, m_size, 0);

	glColor3f (0, 0, 255);
	glVertex3f (0, 0, 0);
	glVertex3f (0, 0, m_size);

	glEnd ();
}
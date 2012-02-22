#include "AxisActor.h"

#include <GL/gl.h>

AxisActor::AxisActor ()
  :size(100)
{
}

AxisActor::~AxisActor ()
{
}

void
AxisActor::draw () const
{
  glBegin (GL_LINES);

  glColor3f (255,0,0);
	glVertex3f (0,0,0);
	glVertex3f (100,0,0);

	glColor3f (0,255,0);
	glVertex3f (0,0,0);
	glVertex3f (0,100,0);

	glColor3f (0,0,255);
	glVertex3f (0,0,0);
	glVertex3f (0,0,100);

	glEnd ();
}
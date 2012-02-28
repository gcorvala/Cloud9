#include "PlaneActor.h"

#include <gl/GL.h>
#include <math.h>

PlaneActor::PlaneActor (const Plane& plane)
{
  if (plane.getTheta () != 0 && plane.getTheta () != M_PI/2) {
    m_p1.x = -1000;
    m_p1.y = -1000;
    m_p1.z = plane.getZValue (m_p1.x, m_p1.y);
    m_p2.x = -1000;
    m_p2.y = 1000;
    m_p2.z = plane.getZValue (m_p2.x, m_p2.y);
    m_p3.x = 1000;
    m_p3.y = 1000;
    m_p3.z = plane.getZValue (m_p3.x, m_p3.y);
    m_p4.x = 1000;
    m_p4.y = -1000;
    m_p4.z = plane.getZValue (m_p4.x, m_p4.y);
  }
  else {
    std::cout << "theta:" << plane.getTheta () << std::endl;
    m_p1.x = -1000;
    m_p1.y = -1000;
    m_p1.z = plane.getZValue (m_p1.x, m_p1.y);
    m_p2.x = -1000;
    m_p2.y = 1000;
    m_p2.z = plane.getZValue (m_p2.x, m_p2.y);
    m_p3.x = 1000;
    m_p3.y = 1000;
    m_p3.z = plane.getZValue (m_p3.x, m_p3.y);
    m_p4.x = 1000;
    m_p4.y = -1000;
    m_p4.z = plane.getZValue (m_p4.x, m_p4.y);  }

  std::cout << "p1:" << m_p1 << std::endl;
  std::cout << "p2:" << m_p2 << std::endl;
  std::cout << "p3:" << m_p3 << std::endl;
  std::cout << "p4:" << m_p4 << std::endl;
}

PlaneActor::~PlaneActor ()
{
}

void
PlaneActor::draw () const
{
  glBegin (GL_QUADS);

  glVertex3f (m_p1.x, m_p1.y, m_p1.z);
  glVertex3f (m_p2.x, m_p2.y, m_p2.z);
  glVertex3f (m_p3.x, m_p3.y, m_p3.z);
  glVertex3f (m_p4.x, m_p4.y, m_p4.z);

  glEnd ();
}
#include "LineActor.h"

#include <gl/GL.h>
#include <math.h>

LineActor::LineActor (const Point& start, const Point& end)
  :m_start(start)
  ,m_end(end)
{
}

LineActor::LineActor (const Line& line)
{
  Float64 e = 2000;
  if (line.getSlope () < M_PI/4) {
    m_start = Point (line.getXValue (e), e , 0);
    m_end = Point (line.getXValue (-e), -e, 0);
  }
  else {
    m_start = Point (e, line.getYValue (e), 0);
    m_end = Point (-e, line.getYValue (-e), 0);
  }
/*  if (line.a != 0 && line.b != 0) {
    std::cout << "1" << std::endl;
    m_start = Point (e, line.getYValue (e), 0);
    m_end = Point (line.getXValue (e), e, 0);
  }
  else if (line.a != 0) {
    std::cout << "2" << std::endl;
    m_start = Point (line.getXValue (e), e , 0);
    m_end = Point (line.getXValue (-e), -e, 0);
  }
  else {
    std::cout << "3" << std::endl;
    m_start = Point (e, line.getYValue (e), 0);
    m_end = Point (-e, line.getYValue (-e), 0);
  }*/
  std::cout << "start: " << m_start << " end: " << m_end << std::endl;
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
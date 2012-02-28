#include "PointCloudActor.h"

#include <GL/gl.h>

PointCloudActor::PointCloudActor (const PointCloud& cloud)
  :m_cloud(&cloud)
  ,m_point_size(3.0f)
{
  PointCloud::const_iterator it;

/*  Point min = cloud.getMin ();
  Point max = cloud.getMax ();
  Point center ((min.x+max.x)/2, (min.y+max.y)/2, (min.z+max.z)/2);*/
    Point center;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    const Point& p = *it;
    vertex_array.push_back (QVector3D (p.x-center.x, p.y-center.y, p.z-center.z));
    color_array.push_back (p.m_color.r);
    color_array.push_back (p.m_color.g);
    color_array.push_back (p.m_color.b);
  }
}

PointCloudActor::~PointCloudActor ()
{
}

void
PointCloudActor::draw () const
{
  glPointSize (m_point_size);

  glEnableClientState (GL_VERTEX_ARRAY);
  glEnableClientState (GL_COLOR_ARRAY);

  glColorPointer (3, GL_UNSIGNED_BYTE, 0, color_array.constData ());
  glVertexPointer (3, GL_FLOAT, 0, vertex_array.constData ());
  glDrawArrays (GL_POINTS, 0, vertex_array.size ());

  glDisableClientState (GL_VERTEX_ARRAY);
  glDisableClientState (GL_COLOR_ARRAY);

  glPointSize (1);
}
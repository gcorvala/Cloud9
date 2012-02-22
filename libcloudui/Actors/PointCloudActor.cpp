#include "PointCloudActor.h"

#include <GL/gl.h>

PointCloudActor::PointCloudActor (const PointCloud& cloud)
  :m_cloud(&cloud)
  ,m_color(255, 0, 0)
{
  PointCloud::const_iterator it;

  Point min = cloud.getMin ();
  Point max = cloud.getMax ();
  Point center ((min.x+max.x)/2, (min.y+max.y)/2, (min.z+max.z)/2);

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    vertex_array.push_back (QVector3D ((*it).x-center.x, (*it).y-center.y, (*it).z-center.z));
  }
}

PointCloudActor::~PointCloudActor ()
{
}

void
PointCloudActor::draw () const
{
  glColor3ub (m_color.r, m_color.g, m_color.b);

  glEnableClientState (GL_VERTEX_ARRAY);
  glVertexPointer (3, GL_FLOAT, 0, vertex_array.constData ());
  glDrawArrays (GL_POINTS, 0, vertex_array.size ());
  glDisableClientState (GL_VERTEX_ARRAY);
}
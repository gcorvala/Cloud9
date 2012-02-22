#ifndef __POINT_CLOUD_ACTOR_H__
#define __POINT_CLOUD_ACTOR_H__

#include "Actor.h"
#include <libcloud/Common/PointCloud.h>
#include <libcloud/Common/Color.h>
#include <QVector>
#include <QVector3D>

class PointCloudActor : public Actor {
  public:
    PointCloudActor (const PointCloud& cloud);
    virtual ~PointCloudActor ();
    void draw () const;
  private:
    const PointCloud* m_cloud;
    Color m_color;
    QVector<QVector3D>  vertex_array;
};

#endif

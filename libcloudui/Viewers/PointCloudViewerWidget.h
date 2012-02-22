#ifndef __POINT_CLOUD_VIEWER_WIDGET_H__
#define __POINT_CLOUD_VIEWER_WIDGET_H__

#include <QGLWidget>
#include <QMap>
#include <libcloud/Common/PointCloud.h>
#include "Actor.h"

class PointCloudViewerWidget : public QGLWidget {
  Q_OBJECT

  public:
    PointCloudViewerWidget (QWidget *parent = 0);
    ~PointCloudViewerWidget ();

    QSize minimumSizeHint () const;
    QSize sizeHint () const;

    void addPointCloud (const QString& key, PointCloud* cloud);

  public slots:
    void setXRotation (int angle);
    void setYRotation (int angle);
    void setZRotation (int angle);

  protected:
    void initializeGL ();
    void paintGL ();
    void resizeGL (int width, int height);
    void mousePressEvent (QMouseEvent* event);
    void mouseMoveEvent (QMouseEvent* event);

  private:
    int x_rotation;
    int y_rotation;
    int z_rotation;
    QPoint last_pos;

    QMap<QString, PointCloud*> clouds;
    Actor* actor;
};

#endif

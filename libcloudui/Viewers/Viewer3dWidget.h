#ifndef __3D_VIEWER_WIDGET_H__
#define __3D_VIEWER_WIDGET_H__

#include <QGLWidget>
#include <QMap>
#include <libcloud/Common/PointCloud.h>
#include <libcloud/Common/Plane.h>
#include "../Actors/Actor.h"

class Viewer3dWidget : public QGLWidget {
  Q_OBJECT

  public:
    Viewer3dWidget (QWidget *parent = 0);
    ~Viewer3dWidget ();

    QSize minimumSizeHint () const;
    QSize sizeHint () const;

    void add (const QString& key, PointCloud* cloud);
    void add (const QString& key, Plane* plane);

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
    void wheelEvent (QWheelEvent* event);

  //private:
    int x_rotation;
    int y_rotation;
    int z_rotation;
    QPoint last_pos;
    Float32 m_zoom_factor;

    std::vector<Actor*> actors;
};

#endif

#ifndef __POINT_CLOUD_VIEWER_H__
#define __POINT_CLOUD_VIEWER_H__

#include <QGLWidget>
#include <QGLBuffer>
#include <libcloud/Common/PointCloud.h>

class GLWidget : public QGLWidget {
  Q_OBJECT

  public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void showCloud (const PointCloud& cloud);

  public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

  signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

  protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

  private:
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
    QColor qtGreen;
    QColor qtPurple;
    std::vector<PointCloud> clouds;
    std::vector<QGLBuffer> buffers;
    QVector<QVector3D>  m_vertexarray;
//    std::vector<QGLBuffer> clouds;
//    std::vector<GLfloat *> c;
};

#endif

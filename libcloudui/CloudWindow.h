#ifndef __CLOUD_WINDOW_H__
#define __CLOUD_WINDOW_H__

#include <QMainWindow>
#include <QWidget>
#include "Viewers/PointCloudViewerWidget.h"
#include <libcloud/Common/PointCloud.h>

class CloudWindow : public QMainWindow {
  Q_OBJECT

  public:
    CloudWindow (QWidget* parent = 0, Qt::WindowFlags flags = 0);
  public slots:
    void load ();
    void quit ();
  private:
    PointCloudViewerWidget viewer;
    PointCloud cloud;
};

#endif

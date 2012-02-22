#include "CloudApplication.h"

#include <QVBoxLayout>
#include "../GraphEditor/GraphEditorWidget.h"
#include "../Viewers/ImageViewerWidget.h"
#include "../Viewers/Viewer3dWidget.h"

CloudApplication::CloudApplication ( int & argc, char ** argv)
  :QApplication(argc, argv, true )
{
  QWidget* window = new QWidget ();
  QVBoxLayout* box = new QVBoxLayout ();
  GraphEditorWidget* editor = new GraphEditorWidget ();
  ImageViewerWidget* image_viewer = new ImageViewerWidget ();
  Viewer3dWidget* cloud_viewer = new Viewer3dWidget ();

  window->setLayout (box);

  box->addWidget (editor);
  box->addWidget (image_viewer);
  box->addWidget (cloud_viewer);

  window->showMaximized ();
  window->raise ();
}

CloudApplication::~CloudApplication ()
{
}
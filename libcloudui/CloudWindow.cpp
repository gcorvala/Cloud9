#include "CloudWindow.h"

#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/Filters/TranslateFilter.h>
#include <libcloud/Filters/ScaleFilter.h>
#include <libcloud/Filters/CropBoxFilter.h>
#include <libcloud/Common/Utils.h>
#include <iostream> // FIXME
#include <algorithm>

CloudWindow::CloudWindow (QWidget* parent, Qt::WindowFlags flags)
  : QMainWindow(parent, flags), gl(this)
{
  QMenu *file;
  QToolBar *tools;
  QAction *quit = new QAction ("&Quit", this);
  QAction *load = new QAction ("&Load", this);

  file = menuBar ()->addMenu ("&File");
  file->addAction (load);
  file->addAction (quit);

  tools = addToolBar ("Tools");
  tools->addAction (load);

  connect (quit, SIGNAL (triggered ()), this, SLOT (quit ()));
  connect (load, SIGNAL (triggered ()), this, SLOT (load ()));

  setCentralWidget (&gl);
}

void
CloudWindow::load ()
{
  QFileDialog *dialog;
  OBJReader reader;

  std::cout << "load" << std::endl;

  QString file = QFileDialog::getOpenFileName (this, "Load a OBJ file", "~", "Point clouds (*.obj)");
  reader.read (file.toStdString (), cloud, false);

  // FIXME
  TranslateFilter *filter;
  Point min_x, max_x;
  Point min_y, max_y;
  Point min_z, max_z;
  min_x = *min_element (cloud.begin (), cloud.end (), comparePointsByXAxis);
  max_x = *max_element (cloud.begin (), cloud.end (), comparePointsByXAxis);
  min_y = *min_element (cloud.begin (), cloud.end (), comparePointsByYAxis);
  max_y = *max_element (cloud.begin (), cloud.end (), comparePointsByYAxis);
  min_z = *min_element (cloud.begin (), cloud.end (), comparePointsByZAxis);
  max_z = *max_element (cloud.begin (), cloud.end (), comparePointsByZAxis);

  /*filter = new TranslateFilter (-((max_x + min_x) / 2).x,
                                -((max_y + min_y) / 2).y,
                                -((max_z + min_z) / 2).z);*/
  CropBoxFilter crop (Point (0, 0, 0), Point (400, 4000, 300));
  //crop.run (cloud);
/*
                              min_x: 32.79
                              min_y: 13.96
                              min_z: 105.28
                              max_x: 3536.63
                              max_y: 2711.1
                              max_z: 1150.9
                              */
  //filter->run (cloud);
  ScaleFilter scale (8);
  scale.run (cloud);
  // END FIXME

  gl.showCloud (cloud);

  std::cout << file.toStdString () << " " << cloud.size () << std::endl;
}

void
CloudWindow::quit ()
{
  std::cout << "quit" << std::endl;
}

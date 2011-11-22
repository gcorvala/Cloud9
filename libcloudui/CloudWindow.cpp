#include "CloudWindow.h"

#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <libcloud/IO/XYZReader.h>
#include <libcloud/Filters/TranslateFilter.h>
#include <libcloud/Filters/ScaleFilter.h>
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
  XYZReader reader;

  std::cout << "load" << std::endl;

  QString file = QFileDialog::getOpenFileName (this, "Load a XYZ file", "~", "Point clouds (*.xyz)");
  reader.read (file.toStdString (), cloud, true);

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

  filter = new TranslateFilter (-((max_x + min_x) / 2).x,
                                -((max_y + min_y) / 2).y,
                                -((max_z + min_z) / 2).z);
  filter->run (cloud);
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

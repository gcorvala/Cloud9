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
  : QMainWindow(parent, flags)
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

  setCentralWidget (&viewer);
}

void
CloudWindow::load ()
{
  QFileDialog *dialog;
  OBJReader reader;

  std::cout << "load" << std::endl;

  QString file = QFileDialog::getOpenFileName (this, "Load a OBJ file", "~", "Point clouds (*.obj)");
  reader.read (file.toStdString (), cloud, false);

  viewer.add ("new", &cloud);

  std::cout << file.toStdString () << " " << cloud.size () << std::endl;
}

void
CloudWindow::quit ()
{
  std::cout << "quit" << std::endl;
}

#include "PathProperty.h"

#include <QFileDialog>

PathProperty::PathProperty (const QString& title, Type type)
  :Property(title)
  ,type(type)
{
  QHBoxLayout* hbox = new QHBoxLayout ();
  layout->addLayout (hbox);
  path = new QLineEdit ();
  hbox->addWidget (path);
  button = new QPushButton ("...");
  hbox->addWidget (button);

  connect (button, SIGNAL (clicked ()), this, SLOT (search ()));
}

PathProperty::~PathProperty ()
{
}

QString
PathProperty::getValue () const
{
  return path->text ();
}

void
PathProperty::search ()
{
  QString file_name;
  switch (type) {
    case OpenFile:
      file_name = QFileDialog::getOpenFileName (this, "Open File", QDir::currentPath ());
      break;
    case SaveFile:
      file_name = QFileDialog::getSaveFileName (this, "Open File", QDir::currentPath ());
      break;
  }
  path->setText (file_name);
}
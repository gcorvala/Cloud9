#include "PathProperty.h"

#include <QFileDialog>

PathProperty::PathProperty (const QString& title)
  :Property(title)
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
  path->setText (QFileDialog::getOpenFileName (this, "Open File", QDir::currentPath ()));
}
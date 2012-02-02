#include "Property.h"

#include <QVBoxLayout>
#include <QLabel>

Property::Property (const QString& title)
{
  layout = new QVBoxLayout ();
  setLayout (layout);
  layout->addWidget (new QLabel (title));
}

Property::~Property ()
{
}
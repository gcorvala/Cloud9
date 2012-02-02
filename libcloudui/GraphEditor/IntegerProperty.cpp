#include "IntegerProperty.h"

IntegerProperty::IntegerProperty (const QString& title, int min, int max, int default_value)
  :Property(title)
{
  spin_box = new QSpinBox ();
  spin_box->setRange (min, max);
  spin_box->setValue (default_value);
  layout->addWidget (spin_box);
}

IntegerProperty::~IntegerProperty ()
{
}

int
IntegerProperty::getValue () const
{
  return spin_box->value ();
}
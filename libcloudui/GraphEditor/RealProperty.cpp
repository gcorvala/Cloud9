#include "RealProperty.h"

RealProperty::RealProperty (const QString& title, qreal min, qreal max, qreal default_value)
  :Property(title)
{
  spin_box = new QDoubleSpinBox ();
  spin_box->setRange (min, max);
  spin_box->setValue (default_value);
  layout->addWidget (spin_box);
}

RealProperty::~RealProperty ()
{
}

qreal
RealProperty::getValue () const
{
  return spin_box->value ();
}
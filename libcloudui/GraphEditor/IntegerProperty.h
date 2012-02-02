#ifndef __INTEGER_PROPERTY_H__
#define __INTEGER_PROPERTY_H__

#include "Property.h"
#include <QSpinBox>

class IntegerProperty : public Property {
  Q_OBJECT

  public:
    IntegerProperty (const QString& title, int min, int max, int default_value);
    ~IntegerProperty ();

    int getValue () const;

  private:
    QSpinBox* spin_box;
};

#endif
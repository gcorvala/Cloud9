#ifndef __REAL_PROPERTY_H__
#define __REAL_PROPERTY_H__

#include "Property.h"
#include <QDoubleSpinBox>

class RealProperty : public Property {
  Q_OBJECT

  public:
    RealProperty (const QString& title, qreal min, qreal max, qreal default_value);
    ~RealProperty ();

    qreal getValue () const;

  private:
    QDoubleSpinBox* spin_box;
};

#endif
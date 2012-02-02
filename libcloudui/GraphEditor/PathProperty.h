#ifndef __REAL_PROPERTY_H__
#define __REAL_PROPERTY_H__

#include "Property.h"
#include <QLineEdit>
#include <QPushButton>

class PathProperty : public Property {
  Q_OBJECT

  public:
    PathProperty (const QString& title);
    ~PathProperty ();

    QString getValue () const;

  private slots:
    void search ();

  private:
    QLineEdit* path;
    QPushButton* button;
};

#endif
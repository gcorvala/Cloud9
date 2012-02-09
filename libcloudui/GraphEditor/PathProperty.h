#ifndef __REAL_PROPERTY_H__
#define __REAL_PROPERTY_H__

#include "Property.h"
#include <QLineEdit>
#include <QPushButton>

class PathProperty : public Property {
  Q_OBJECT

  public:
    enum Type {
      OpenFile,
      SaveFile
    };

    PathProperty (const QString& title, Type type = OpenFile);
    ~PathProperty ();

    QString getValue () const;

  private slots:
    void search ();

  private:
    QLineEdit* path;
    QPushButton* button;
    Type type;
};

#endif
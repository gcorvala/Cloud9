#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <QWidget>
#include <QBoxLayout>

class Property : public QWidget {
  Q_OBJECT

  public:
    Property (const QString& title);
    ~Property ();

  public slots:

  signals:

  protected:
    QBoxLayout* layout;
};

#endif
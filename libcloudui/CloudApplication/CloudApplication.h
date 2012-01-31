#ifndef __CLOUD_APPLICATION_H__
#define __CLOUD_APPLICATION_H__

#include <QApplication>

class CloudApplication : public QApplication {
  public:
    CloudApplication ( int & argc, char ** argv);
    ~CloudApplication ();
  protected:
  private:
};

#endif
#ifndef __IMAGE_VIEWER_WIDGET_H__
#define __IMAGE_VIEWER_WIDGET_H__

#include <QScrollArea>
#include <QLabel>
#include <libcloud/2D/Image.h>

class ImageViewerWidget : public QScrollArea {
  Q_OBJECT

  public:
    ImageViewerWidget (QWidget* parent = 0);
    virtual ~ImageViewerWidget ();

    void setImage (const Image* _image);

  public slots:

  signals:

  protected:

  private:
    QLabel image;
};

#endif
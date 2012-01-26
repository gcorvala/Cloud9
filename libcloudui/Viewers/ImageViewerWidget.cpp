#include "ImageViewerWidget.h"

#include <QImage>

ImageViewerWidget::ImageViewerWidget (QWidget* parent)
{
  setBackgroundRole (QPalette::Dark);
  setWidget (&image);
}

ImageViewerWidget::~ImageViewerWidget ()
{
}

void
ImageViewerWidget::setImage (const Image* _image)
{
  QImage im (_image->getCols (), _image->getRows (), QImage::Format_RGB888);

  for (unsigned int i = 0; i < _image->getRows (); ++i) {
    for (unsigned int j = 0; j < _image->getCols (); ++j) {
      Color c = _image->getPixel (i, j);
      im.setPixel (j, i, qRgb (c.r, c.g, c.b));
    }
  }

  image.setPixmap (QPixmap::fromImage (im));

  image.adjustSize();
}

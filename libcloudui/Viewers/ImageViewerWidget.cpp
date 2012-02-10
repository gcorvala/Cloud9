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

void
ImageViewerWidget::setMatrix (const Matrix<UInt8>* matrix)
{
  QImage im (matrix->getCols (), matrix->getRows (), QImage::Format_RGB888);

  for (unsigned int i = 0; i < matrix->getRows (); ++i) {
    for (unsigned int j = 0; j < matrix->getCols (); ++j) {
      Color c (matrix->at (i, j));
      im.setPixel (j, i, qRgb (c.r, c.g, c.b));
    }
  }

  image.setPixmap (QPixmap::fromImage (im));

  image.adjustSize();
}

void
ImageViewerWidget::setMatrix (const Matrix<UInt32>* matrix)
{
  QImage im (matrix->getCols (), matrix->getRows (), QImage::Format_RGB888);

  for (unsigned int i = 0; i < matrix->getRows (); ++i) {
    for (unsigned int j = 0; j < matrix->getCols (); ++j) {
      UInt32 value = matrix->at (i, j);
      im.setPixel (j, i, qRgb (value, value, value));
    }
  }

  image.setPixmap (QPixmap::fromImage (im));

  image.adjustSize();
}
#include "ImageReaderThread.h"

#include <QImage>
#include <libcloud/Common/Color.h>

ImageReaderThread::ImageReaderThread (QObject* parent)
  :NodeThread(parent)
{
  path = "building.jpg";
}

ImageReaderThread::~ImageReaderThread ()
{
}

void
ImageReaderThread::run ()
{
  qDebug ("ImageReaderThread::run start");
  QImage image (path);
  qDebug ("ImageReaderThread::run %d:%d", image.height (), image.width ());

  output->resize (image.height (), image.width ());

  for (UInt32 i = 0; i < image.height (); ++i) {
    for (UInt32 j = 0; j < image.width (); ++j) {
      QRgb c = image.pixel (j, i);
      output->at (i, j) = Color (qRed (c), qGreen (c), qBlue (c)).getY ();
    }
  }
  qDebug ("ImageReaderThread::run end");
}

void
ImageReaderThread::setOutputPtr (Matrix<UInt8>* ptr)
{
  output = ptr;
}
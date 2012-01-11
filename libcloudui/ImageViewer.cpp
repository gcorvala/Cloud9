#include <iostream>
 #include <QtGui>

 #include "ImageViewer.h"
 #include "libcloud/2D/Image.h"
 #include "libcloud/2D/SobelEstimator.h"
 #include "libcloud/2D/ScharrEstimator.h"
 #include "libcloud/2D/ThresholdEstimator.h"
 #include "libcloud/2D/HoughEstimator.h"
 #include "libcloud/2D/GaussianEstimator.h"
 #include "libcloud/2D/CannyEstimator.h"
 #include "libcloud/IO/OBJReader.h"
 #include "libcloud/Common/PointCloud.h"

 ImageViewer::ImageViewer()
 {
     imageLabel = new QLabel;
     imageLabel->setBackgroundRole(QPalette::Base);
     imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
     imageLabel->setScaledContents(true);

     scrollArea = new QScrollArea;
     scrollArea->setBackgroundRole(QPalette::Dark);
     scrollArea->setWidget(imageLabel);
     setCentralWidget(scrollArea);

     createActions();
     createMenus();

     setWindowTitle(tr("Image Viewer"));
     resize(500, 400);
 }

 void ImageViewer::open()
 {
     QString fileName = QFileDialog::getOpenFileName(this,
                                     tr("Open File"), QDir::currentPath());
     if (!fileName.isEmpty()) {
         QImage image(fileName);
         if (image.isNull()) {
             QMessageBox::information(this, tr("Image Viewer"),
                                      tr("Cannot load %1.").arg(fileName));
             return;
         }

//         Image im(image.height (), image.width ());
         Matrix<UInt8> m (image.height (), image.width ());

         for (unsigned int i = 0; i < image.height (); ++i) {
           for (unsigned int j = 0; j < image.width (); ++j) {
             QRgb c = image.pixel (j, i);
//             im.setPixel(i,j, Color (qRed (c), qGreen (c), qBlue (c)));
             m(i,j) = Color (qRed (c), qGreen (c), qBlue (c)).getY();
//             image.setPixel (j, i, qRgb (im.getPixel(i,j).getY (), im.getPixel(i,j).getY (), im.getPixel(i,j).getY ()));
           }
         }

         Matrix<UInt8> out1;
         Matrix<UInt8> out2;

         HoughEstimator hough;
         ThresholdEstimator threshold;
         CannyEstimator canny;

         threshold.setThreshold (70);

         canny.compute (m, out1);
         threshold.compute (out1, out2);
         //int a = 1000;
         //out2.resize (a, a);
         //for (int i = 0; i < a; i++) out2(i,i) = 255;
//         hough.compute (out2, out1);

//         std::vector<Line> lines;
//         hough.getLines (out2, out1, lines);
         
           Matrix<UInt8> out = out2;
        image = QImage (out.getCols (), out.getRows (), QImage::Format_RGB32);
        /*OBJReader reader;
        PointCloud cloud;

        reader.read ("../Code/data/obj/Bunker001.obj", cloud, false);
        UInt32 s = 4096;
        Matrix<UInt32> plan (s, s);
        for (PointCloud::const_iterator it = cloud.begin (); it != cloud.end (); ++it) {
          const Point& p = *it;
          plan(round (p.y), round (p.z))++;
        }
        threshold.setThreshold (1);
        Matrix<UInt8> plan1;
        plan1 = plan;
        Matrix<UInt8> plan2 (s, s);
        threshold.compute (plan1, plan2);*/

        //hough.compute (plan2, plan1);
        //canny.compute (plan1, plan2);
        //threshold.setThreshold (128);
        //threshold.compute (plan2, plan1);
          Matrix<UInt8> plan2;
        plan2 = out;
        //hough.getLines (plan2, plan1, lines);
        
        image = QImage (plan2.getCols (), plan2.getRows (), QImage::Format_RGB32);
        
        for (unsigned int i = 0; i < plan2.getRows (); ++i) {
           for (unsigned int j = 0; j < plan2.getCols (); ++j) {
             image.setPixel (j, i, qRgb (plan2(i,j), plan2(i,j), plan2(i,j)));
           }
         }
         /*for (unsigned int i = 0; i < out.getRows (); ++i) {
           for (unsigned int j = 0; j < out.getCols (); ++j) {
             image.setPixel (j, i, qRgb (out(i,j), out(i,j), out(i,j)));
           }
         }*/

         imageLabel->setPixmap(QPixmap::fromImage(image));
         scaleFactor = 1.0;

         printAct->setEnabled(true);
         fitToWindowAct->setEnabled(true);
         updateActions();

         if (!fitToWindowAct->isChecked())
             imageLabel->adjustSize();
     }
 }

 void ImageViewer::print()
 {
     Q_ASSERT(imageLabel->pixmap());
 #ifndef QT_NO_PRINTER
     QPrintDialog dialog(&printer, this);
     if (dialog.exec()) {
         QPainter painter(&printer);
         QRect rect = painter.viewport();
         QSize size = imageLabel->pixmap()->size();
         size.scale(rect.size(), Qt::KeepAspectRatio);
         painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
         painter.setWindow(imageLabel->pixmap()->rect());
         painter.drawPixmap(0, 0, *imageLabel->pixmap());
     }
 #endif
 }

 void ImageViewer::zoomIn()
 {
     scaleImage(1.25);
 }

 void ImageViewer::zoomOut()
 {
     scaleImage(0.8);
 }

 void ImageViewer::normalSize()
 {
     imageLabel->adjustSize();
     scaleFactor = 1.0;
 }

 void ImageViewer::fitToWindow()
 {
     bool fitToWindow = fitToWindowAct->isChecked();
     scrollArea->setWidgetResizable(fitToWindow);
     if (!fitToWindow) {
         normalSize();
     }
     updateActions();
 }

 void ImageViewer::about()
 {
     QMessageBox::about(this, tr("About Image Viewer"),
             tr("<p>The <b>Image Viewer</b> example shows how to combine QLabel "
                "and QScrollArea to display an image. QLabel is typically used "
                "for displaying a text, but it can also display an image. "
                "QScrollArea provides a scrolling view around another widget. "
                "If the child widget exceeds the size of the frame, QScrollArea "
                "automatically provides scroll bars. </p><p>The example "
                "demonstrates how QLabel's ability to scale its contents "
                "(QLabel::scaledContents), and QScrollArea's ability to "
                "automatically resize its contents "
                "(QScrollArea::widgetResizable), can be used to implement "
                "zooming and scaling features. </p><p>In addition the example "
                "shows how to use QPainter to print an image.</p>"));
 }

 void ImageViewer::createActions()
 {
     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcut(tr("Ctrl+O"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     printAct = new QAction(tr("&Print..."), this);
     printAct->setShortcut(tr("Ctrl+P"));
     printAct->setEnabled(false);
     connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcut(tr("Ctrl+Q"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     zoomInAct = new QAction(tr("Zoom &In (25%)"), this);
     zoomInAct->setShortcut(tr("Ctrl++"));
     zoomInAct->setEnabled(false);
     connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

     zoomOutAct = new QAction(tr("Zoom &Out (25%)"), this);
     zoomOutAct->setShortcut(tr("Ctrl+-"));
     zoomOutAct->setEnabled(false);
     connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));

     normalSizeAct = new QAction(tr("&Normal Size"), this);
     normalSizeAct->setShortcut(tr("Ctrl+S"));
     normalSizeAct->setEnabled(false);
     connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(normalSize()));

     fitToWindowAct = new QAction(tr("&Fit to Window"), this);
     fitToWindowAct->setEnabled(false);
     fitToWindowAct->setCheckable(true);
     fitToWindowAct->setShortcut(tr("Ctrl+F"));
     connect(fitToWindowAct, SIGNAL(triggered()), this, SLOT(fitToWindow()));

     aboutAct = new QAction(tr("&About"), this);
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("About &Qt"), this);
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
 }

 void ImageViewer::createMenus()
 {
     fileMenu = new QMenu(tr("&File"), this);
     fileMenu->addAction(openAct);
     fileMenu->addAction(printAct);
     fileMenu->addSeparator();
     fileMenu->addAction(exitAct);

     viewMenu = new QMenu(tr("&View"), this);
     viewMenu->addAction(zoomInAct);
     viewMenu->addAction(zoomOutAct);
     viewMenu->addAction(normalSizeAct);
     viewMenu->addSeparator();
     viewMenu->addAction(fitToWindowAct);

     helpMenu = new QMenu(tr("&Help"), this);
     helpMenu->addAction(aboutAct);
     helpMenu->addAction(aboutQtAct);

     menuBar()->addMenu(fileMenu);
     menuBar()->addMenu(viewMenu);
     menuBar()->addMenu(helpMenu);
 }

 void ImageViewer::updateActions()
 {
     zoomInAct->setEnabled(!fitToWindowAct->isChecked());
     zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
     normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
 }

 void ImageViewer::scaleImage(double factor)
 {
     Q_ASSERT(imageLabel->pixmap());
     scaleFactor *= factor;
     imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

     adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
     adjustScrollBar(scrollArea->verticalScrollBar(), factor);

     zoomInAct->setEnabled(scaleFactor < 3.0);
     zoomOutAct->setEnabled(scaleFactor > 0.333);
 }

 void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
 {
     scrollBar->setValue(int(factor * scrollBar->value()
                             + ((factor - 1) * scrollBar->pageStep()/2)));
 }
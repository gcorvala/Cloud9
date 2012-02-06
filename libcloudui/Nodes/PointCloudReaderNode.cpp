#include "PointCloudReaderNode.h"
#include "../GraphEditor/PathProperty.h"

#include <libcloud/IO/FileReader.h>
#include <libcloud/IO/XYZReader.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/IO/PCDReader.h>
#include <QFileInfo>

PointCloudReaderNode::PointCloudReaderNode ()
  :Node("PointCloud Reader")
  ,thread(this)
{
  addOutputAnchor ("PointCloud");
  addProperty ("input-file", new PathProperty ("Input file"));
}

PointCloudReaderNode::~PointCloudReaderNode ()
{
}

void
PointCloudReaderNode::preProcess ()
{
  Node::preProcess ();
  thread.path = ((PathProperty*) properties["input-file"])->getValue ();
}

void
PointCloudReaderNode::process ()
{
  thread.start ();
}

void
PointCloudReaderNode::postProcess ()
{
  outputs["PointCloud"]->setValue (&(thread.output));
  Node::postProcess ();
}

PointCloudReaderNode::PointCloudReaderThread::PointCloudReaderThread (Node* parent)
  :NodeThread(parent)
{
}

PointCloudReaderNode::PointCloudReaderThread::~PointCloudReaderThread ()
{
}

void
PointCloudReaderNode::PointCloudReaderThread::run ()
{
  FileReader* reader;
  QFileInfo info (path);
  QString suffix = info.suffix ();

  if (suffix == "xyz") {
    reader = (FileReader*) new XYZReader ();
  }
  else if (suffix == "obj") {
    reader = (FileReader*) new OBJReader ();
  }
  else if (suffix == "pcd") {
    reader = (FileReader*) new PCDReader ();
  }
  else {
    qDebug ("PointCloudReaderNode::PointCloudReaderThread::run error");
  }

  // FIXME : binary ?
  reader->read (path.toStdString (), output, false);

  qDebug ("PointCloudReaderNode::PointCloudReaderThread::run size:%d", output.size ());
}
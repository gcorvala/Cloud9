#include "GraphToolBar.h"

#include <QIcon>
#include "../Nodes/CannyNode.h"
#include "../Nodes/GaussianNode.h"
#include "../Nodes/HoughNode.h"
#include "../Nodes/ImageNode.h"
#include "../Nodes/ImageReaderNode.h"
#include "../Nodes/ImageWriterNode.h"
#include "../Nodes/PhaseCongruencyNode.h"
#include "../Nodes/PointCloudReaderNode.h"
#include "../Nodes/SobelNode.h"
#include "../Nodes/TestNode.h"
#include "../Nodes/ThresholdNode.h"
#include "../Nodes/ViewerNode.h"

GraphToolBar::GraphToolBar ()
  :QToolBar("Graph Tool Bar")
{
}

GraphToolBar::~GraphToolBar ()
{
}

void
GraphToolBar::setGraph (Graph* _graph)
{
  QAction* action;
  graph = _graph;
  QIcon icon = QIcon::fromTheme ("insert-object");
  action = addAction (icon, "Test", this, SLOT (addNode1 ()));
  action = addAction (icon, "Image Reader", this, SLOT (addNode2 ()));
  action = addAction (icon, "Gaussian", this, SLOT (addNode3 ()));
  action = addAction (icon, "Viewer", this, SLOT (addNode4 ()));
  action = addAction (icon, "Sobel", this, SLOT (addNode5 ()));
  action = addAction (icon, "Image", this, SLOT (addNode6 ()));
  action = addAction (icon, "Phase", this, SLOT (addNode7 ()));
  action = addAction (icon, "Threshold", this, SLOT (addNode8 ()));
  action = addAction (icon, "Canny", this, SLOT (addNode9 ()));
  action = addAction (icon, "Point Cloud Reader", this, SLOT (addNode10 ()));
  action = addAction (icon, "Hough", this, SLOT (addNode11 ()));
  action = addAction (icon, "Image Writer", this, SLOT (addNode12 ()));
}

Graph*
GraphToolBar::getGraph () const
{
  return graph;
}

void
GraphToolBar::addNode1 ()
{
  graph->addNode (new TestNode ());
}

void
GraphToolBar::addNode2 ()
{
  graph->addNode (new ImageReaderNode ());
}

void
GraphToolBar::addNode3 ()
{
  graph->addNode (new GaussianNode ());
}

void
GraphToolBar::addNode4 ()
{
  graph->addNode (new ViewerNode ());
}

void
GraphToolBar::addNode5 ()
{
  graph->addNode (new SobelNode ());
}

void
GraphToolBar::addNode6 ()
{
  graph->addNode (new ImageNode ());
}

void
GraphToolBar::addNode7 ()
{
  graph->addNode (new PhaseCongruencyNode ());
}

void
GraphToolBar::addNode8 ()
{
  graph->addNode (new ThresholdNode ());
}

void
GraphToolBar::addNode9 ()
{
  graph->addNode (new CannyNode ());
}

void
GraphToolBar::addNode10 ()
{
  graph->addNode (new PointCloudReaderNode ());
}

void
GraphToolBar::addNode11 ()
{
  graph->addNode (new HoughNode ());
}

void
GraphToolBar::addNode12 ()
{
  graph->addNode (new ImageWriterNode ());
}
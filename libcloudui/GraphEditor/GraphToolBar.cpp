#include "GraphToolBar.h"

#include <QIcon>
#include "GaussianNode.h"
#include "ImageNode.h"
#include "ImageReaderNode.h"
#include "SobelNode.h"
#include "TestNode.h"
#include "ViewerNode.h"

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
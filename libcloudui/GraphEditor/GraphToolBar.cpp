#include "GraphToolBar.h"

#include <QIcon>
#include "GaussianNode.h"
#include "ImageReaderNode.h"
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
  action = addAction (icon, "Node 1", this, SLOT (addNode1 ()));
  action = addAction (icon, "Node 2", this, SLOT (addNode2 ()));
  action = addAction (icon, "Node 3", this, SLOT (addNode3 ()));
  action = addAction (icon, "Node 4", this, SLOT (addNode4 ()));
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
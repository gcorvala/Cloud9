#include "GraphToolBar.h"

#include <QIcon>

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
  graph = _graph;
  QIcon icon = QIcon::fromTheme ("insert-object");
  QAction* action = addAction (icon, "Insert", graph, SLOT (addNode ()));
}

Graph*
GraphToolBar::getGraph () const
{
  return graph;
}
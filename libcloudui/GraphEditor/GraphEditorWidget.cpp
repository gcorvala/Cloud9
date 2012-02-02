#include "GraphEditorWidget.h"

#include "Graph.h"
#include "GraphToolBar.h"

#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

GraphEditorWidget::GraphEditorWidget (QWidget *parent)
  :QWidget(parent)
{
  QVBoxLayout* layout = new QVBoxLayout (this);

  GraphToolBar* tool_bar = new GraphToolBar ();

  layout->addWidget (tool_bar);

  h_layout = new QHBoxLayout ();

  QGraphicsView* graph_view = new QGraphicsView ();

  graph_view->setRenderHint (QPainter::Antialiasing);

  Graph* graph = new Graph ();

  tool_bar->setGraph (graph);

  graph_view->setScene (graph);

  h_layout->addWidget (graph_view);
  properties = new QWidget ();
  h_layout->addWidget (properties);

  layout->addLayout (h_layout);

  connect (graph, SIGNAL (nodeSelectedEvent (Node*)), this, SLOT (displayProperty (Node*)));
}

GraphEditorWidget::~GraphEditorWidget ()
{
}

void
GraphEditorWidget::displayProperty (Node* node)
{
  qDebug ("GraphEditorWidget::displayProperty");
  h_layout->removeWidget (properties);
  properties->hide ();
  properties = node->getPropertyWidget ();
  h_layout->addWidget (properties);
}
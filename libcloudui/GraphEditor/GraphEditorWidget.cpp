#include "GraphEditorWidget.h"

#include "Graph.h"
#include "GraphToolBar.h"

#include <QGraphicsView>
#include <QVBoxLayout>

GraphEditorWidget::GraphEditorWidget (QWidget *parent)
  :QWidget(parent)
{
  QVBoxLayout* layout = new QVBoxLayout (this);

  GraphToolBar* tool_bar = new GraphToolBar ();

  layout->addWidget (tool_bar);

  QGraphicsView* graph_view = new QGraphicsView ();

  graph_view->setRenderHint (QPainter::Antialiasing);

  Graph* graph = new Graph ();

  tool_bar->setGraph (graph);

  graph_view->setScene (graph);

  layout->addWidget (graph_view);
}

GraphEditorWidget::~GraphEditorWidget ()
{
}
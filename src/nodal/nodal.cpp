#include <QApplication>
#include <QGraphicsView>
#include <libcloudui/Node.h>
#include <libcloudui/Edge.h>
#include <libcloudui/Graph.h>

int main (int argc, char *argv[])
{
  QList<Anchor *> anchors;
  QApplication app (argc, argv);

  Graph graph;

  Node* node_a = new Node ("Node A");
  node_a->setPos (0, 0);

  graph.addItem (node_a);

  Node* node_b = new Node ("Node B");
  node_b->setPos (150, 0);

  graph.addItem (node_b);

  Node* node_c = new Node ("Node C");
  node_c->setPos (300, 0);

  graph.addItem (node_c);

  anchors = node_a->getOutputAnchors ();

  Edge* edge_a = new Edge (*node_a->getOutputAnchors ()[0], *node_b->getInputAnchors ()[1]);
  graph.addItem (edge_a);

  Edge* edge_b = new Edge (*node_a->getOutputAnchors ()[1], *node_c->getInputAnchors ()[0]);
  graph.addItem (edge_b);

  Edge* edge_c = new Edge (*node_b->getOutputAnchors ()[0], *node_c->getInputAnchors ()[1]);
  graph.addItem (edge_c);

  QGraphicsView view (&graph);

  view.setRenderHint (QPainter::Antialiasing);

  view.show ();

  return app.exec ();
}
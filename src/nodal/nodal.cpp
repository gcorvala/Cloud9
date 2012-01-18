#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>
#include <QTabWidget>
#include <libcloudui/Node.h>
#include <libcloudui/Edge.h>

int main (int argc, char *argv[])
{
  QApplication app (argc, argv);

  QGraphicsScene scene;

  scene.setBackgroundBrush (QBrush (QColor (252, 255, 245)));
  scene.setSceneRect(-100, -100, 600, 600);

  Node* node_a = new Node ("Node A");
  node_a->setPos (0, 0);

  scene.addItem (node_a);

  Node* node_b = new Node ("Node B");
  node_b->setPos (150, 0);

  scene.addItem (node_b);

  Node* node_c = new Node ("Node C");
  node_c->setPos (300, 0);

  scene.addItem (node_c);

  Edge* edge_a = new Edge (*node_a, *node_b);
  scene.addItem (edge_a);

  Edge* edge_b = new Edge (*node_b, *node_c);
  scene.addItem (edge_b);

  QGraphicsView view (&scene);

  view.setRenderHint (QPainter::Antialiasing);

  view.show ();

  return app.exec ();
}
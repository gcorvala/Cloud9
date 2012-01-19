#include <QApplication>
#include <QGraphicsView>
#include <libcloudui/GraphEditor/GraphEditorWidget.h>

int main (int argc, char *argv[])
{
  QApplication app (argc, argv);

  GraphEditorWidget *editor = new GraphEditorWidget ();

  editor->show ();

  return app.exec ();
}
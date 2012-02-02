#ifndef __GRAPH_EDITOR_WIDGET_H__
#define __GRAPH_EDITOR_WIDGET_H__

#include <QWidget>
#include "Node.h"

class GraphEditorWidget : public QWidget {
  Q_OBJECT

  public:
    GraphEditorWidget (QWidget *parent = 0);
    virtual ~GraphEditorWidget ();

  public slots:
    void displayProperty (Node* node);

  signals:

  protected:

  private:
    QWidget* properties;
    QHBoxLayout* h_layout;
};

#endif
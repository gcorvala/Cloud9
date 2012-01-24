#ifndef __GRAPH_TOOL_BAR_H__
#define __GRAPH_TOOL_BAR_H__

#include <QToolBar>
#include "Graph.h"

class GraphToolBar : public QToolBar {
  Q_OBJECT

  public:
    GraphToolBar ();
    virtual ~GraphToolBar ();

    void setGraph (Graph* _graph);
    Graph* getGraph () const;

  public slots:
    // FIXME
    void addNode1 ();
    void addNode2 ();
    void addNode3 ();
    void addNode4 ();
  signals:

  protected:

  private:
    Graph *graph;
};

#endif
#ifndef __GRAPH_TOOL_BAR_H__
#define __GRAPH_TOOL_BAR_H__

#include <QToolBar>
#include "Node.h"
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
    void addNode5 ();
    void addNode6 ();
    void addNode7 ();
    void addNode8 ();
    void addNode9 ();
    void addNode10 ();
    void addNode11 ();

  protected:

  private:
    Graph *graph;
};

#endif
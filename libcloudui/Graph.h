#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <QGraphicsScene>

class Graph : public QGraphicsScene {
  Q_OBJECT

  public:
    Graph ();
    virtual ~Graph ();

  public slots:

  signals:

  protected:

  private:
    QColor background_color;
};

#endif
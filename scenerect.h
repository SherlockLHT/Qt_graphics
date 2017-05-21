#ifndef SCENERECT_H
#define SCENERECT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class sceneRect : public QGraphicsScene
{
public:
    sceneRect();

private:
    QGraphicsRectItem* rectItem;
};

#endif // SCENERECT_H

#ifndef SCENECIRCULAR_H
#define SCENECIRCULAR_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class sceneCircular : public QGraphicsScene
{
public:
    sceneCircular();

private:
    QGraphicsEllipseItem* circuItem;
};

#endif // SCENECIRCULAR_H

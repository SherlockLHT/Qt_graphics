#include "scenecircular.h"

sceneCircular::sceneCircular()
{
    setSceneRect(-300, -300, 600, 600);

    circuItem = new QGraphicsEllipseItem;
    circuItem->setBrush(Qt::red);
    circuItem->setRect(0, 0, 50, 50);

    addItem(circuItem);
}


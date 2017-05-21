#include "scenerect.h"

sceneRect::sceneRect()
{
    setSceneRect(-300, -300, 600, 600);

    rectItem = new QGraphicsRectItem;
    rectItem->setBrush(Qt::green);
    rectItem->setRect(0, 0, 50, 50);

    addItem(rectItem);
}


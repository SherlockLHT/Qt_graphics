#include "scenetriangle.h"

sceneTriangle::sceneTriangle()
{
    triItem = new QGraphicsPolygonItem;
    triItem->setBrush(Qt::blue);

    QVector<QPoint> polygon_point;
    polygon_point.append(QPoint(0, 0));
    polygon_point.append(QPoint(0, 50));
    polygon_point.append(QPoint(-50, 25));

    QPolygon polygon(polygon_point);
    triItem->setPolygon(polygon);

    addItem(triItem);
}


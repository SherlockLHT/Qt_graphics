#ifndef SCENETRIANGLE_H
#define SCENETRIANGLE_H

#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QPolygon>
#include <QPoint>
#include <QVector>

class sceneTriangle : public QGraphicsScene
{
public:
    sceneTriangle();

private:
    QGraphicsPolygonItem* triItem;
};

#endif // SCENETRIANGLE_H

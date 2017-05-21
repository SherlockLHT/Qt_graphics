#include "scenerect.h"

SceneRect::SceneRect():
    sceneLeftTopPos(QPointF(-100, -100)), sceneSize(QSizeF(300, 200)),
    itemLeftPos(QPointF(0, 0)), itemSize(QSizeF(50, 50)),updateTime(500),
    xStep(10), yStep(10)
{
    setSceneRect(QRectF(sceneLeftTopPos, sceneSize));   //场景大小

    rectItem = new QGraphicsRectItem(QRectF(itemLeftPos, itemSize));    //矩形图形项
    rectItem->setBrush(Qt::green);

    lineLeft = new QGraphicsLineItem
            ( sceneLeftTopPos.x(), sceneLeftTopPos.y(), sceneLeftTopPos.x(),
              sceneLeftTopPos.y() + sceneSize.height());

    lineRight = new QGraphicsLineItem
            ( sceneLeftTopPos.x() + sceneSize.width(), sceneLeftTopPos.y(),
              sceneLeftTopPos.x() + sceneSize.width(), sceneLeftTopPos.y() + sceneSize.height());

    lineTop = new QGraphicsLineItem
            ( sceneLeftTopPos.x(), sceneLeftTopPos.x(),
              sceneLeftTopPos.x() + sceneSize.width(), sceneLeftTopPos.y());

    lineBottom = new QGraphicsLineItem
            ( sceneLeftTopPos.x(), sceneLeftTopPos.y() + sceneSize.height(),
              sceneLeftTopPos.x() + sceneSize.width(), sceneLeftTopPos.y() + sceneSize.height() );

    addItem(rectItem);
    addItem(lineLeft);
    addItem(lineRight);
    addItem(lineTop);
    addItem(lineBottom);
}

SceneRect::~SceneRect()
{
    delete rectItem;

    rectItem = NULL;
}

void SceneRect::AddSteps()
{
    killTimer(timerID);

    updateTime = updateTime > 1? updateTime - 10: updateTime;

    timerID = startTimer(updateTime);
}

void SceneRect::ReduceSteps()
{
    killTimer(timerID);

    updateTime = updateTime < 3000? updateTime + 10: updateTime;

    timerID = startTimer(updateTime);
}

void SceneRect::StartMove()
{
    timerID = startTimer(updateTime);
}
void SceneRect::StopMove()
{
    killTimer(timerID);
}

void SceneRect::SetSceneSize(const QSize &size)
{
    //setSceneRect(-300, -300, size.width(), size.height());
}

void SceneRect::timerEvent(QTimerEvent *)
{
    rectItem->moveBy(xStep, yStep);

    if(rectItem->collidesWithItem(lineLeft) || rectItem->collidesWithItem(lineRight))
    {
        xStep = -xStep;
    }
    if(rectItem->collidesWithItem(lineTop) || rectItem->collidesWithItem(lineBottom))
    {
        yStep = -yStep;
    }
}

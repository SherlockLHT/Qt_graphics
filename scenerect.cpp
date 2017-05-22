#include "scenerect.h"

SceneRect::SceneRect():
    sceneLeftTopPos(QPointF(-100, -100)), sceneSize(QSizeF(300, 200)),
    itemLeftPos(QPointF(0, 0)), itemSize(QSizeF(50, 50)),updateTime(100),
    xStep(1), yStep(1), isMoving(false)
{
    setSceneRect(QRectF(sceneLeftTopPos, sceneSize));   //场景大小

    rectItem = new QGraphicsRectItem(QRectF(itemLeftPos, itemSize));    //矩形图形项

    rectItem->setBrush(Qt::green);

    //在场景四周新建四条线
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
    //添加item到scene
    addItem(rectItem);
    addItem(lineLeft);
    addItem(lineRight);
    addItem(lineTop);
    addItem(lineBottom);
}

SceneRect::~SceneRect()
{
    delete rectItem;
    delete lineLeft;
    delete lineRight;
    delete lineTop;
    delete lineBottom;

    lineLeft    = NULL;
    lineRight   = NULL;
    lineTop     = NULL;
    lineBottom  = NULL;
    rectItem    = NULL;
}

void SceneRect::SetStep(qreal x_step, qreal y_step)
{
    xStep = x_step;
    yStep = y_step;
}

void SceneRect::AddSteps()
{
    killTimer(timerID);

    updateTime = updateTime > 5? updateTime - 5: updateTime;

    timerID = startTimer(updateTime);

    qDebug()<<"Update Time:"<<updateTime;
}

void SceneRect::ReduceSteps()
{
    killTimer(timerID);

    updateTime = updateTime <500? updateTime + 5: updateTime;

    timerID = startTimer(updateTime);

    qDebug()<<"Update Time:"<<updateTime;
}

void SceneRect::StartMove()
{
    if( !isMoving )
    {
        timerID = startTimer(updateTime);
        isMoving = true;
    }
}

void SceneRect::StopMove()
{
    if( isMoving )
    {
        killTimer(timerID);
        isMoving = false;
    }
}

void SceneRect::SetSceneSize(const QSizeF& size)
{

}

void SceneRect::timerEvent(QTimerEvent *)
{
    rectItem->moveBy(xStep, yStep);   //相对移动

    //左右边碰撞
    if(rectItem->collidesWithItem(lineLeft) || rectItem->collidesWithItem(lineRight))
    {
        xStep = -xStep;
    }
    //上下边碰撞
    if(rectItem->collidesWithItem(lineTop) || rectItem->collidesWithItem(lineBottom))
    {
        yStep = -yStep;
    }
}

#include "scenecircular.h"

SceneCircular::SceneCircular():
    sceneLeftTopPos(QPointF(-100, -100)), sceneSize(QSizeF(300, 200)),
    itemLeftPos(QPointF(0, 0)), itemSize(QSizeF(50, 50)),updateTime(100),
    xStep(1), yStep(1), isMoving(false)
{
    setSceneRect(QRectF(sceneLeftTopPos, sceneSize));   //场景大小

    circularItem = new QGraphicsEllipseItem(QRectF(itemLeftPos, itemSize));    //圆形图形项

    circularItem->setBrush(Qt::green);
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
    addItem(circularItem);
    addItem(lineLeft);
    addItem(lineRight);
    addItem(lineTop);
    addItem(lineBottom);
}

SceneCircular::~SceneCircular()
{
    delete circularItem;
    delete lineLeft;
    delete lineRight;
    delete lineTop;
    delete lineBottom;

    lineLeft    = NULL;
    lineRight   = NULL;
    lineTop     = NULL;
    lineBottom  = NULL;
    circularItem = NULL;
}

void SceneCircular::AddSteps()
{
    killTimer(timerID);

    updateTime = updateTime > 5? updateTime - 5: updateTime;

    timerID = startTimer(updateTime);

    qDebug()<<"Update Time:"<<updateTime;
}

void SceneCircular::ReduceSteps()
{
    killTimer(timerID);

    updateTime = updateTime <500? updateTime + 5: updateTime;

    timerID = startTimer(updateTime);

    qDebug()<<"Update Time:"<<updateTime;
}

void SceneCircular::StartMove()
{
    if( !isMoving )
    {
        timerID = startTimer(updateTime);
        isMoving = true;
    }
}
void SceneCircular::StopMove()
{
    if( isMoving )
    {
        killTimer(timerID);
        isMoving = false;
    }
}

void SceneCircular::SetSceneSize(const QSize &size)
{
    //setsceneCircular(-300, -300, size.width(), size.height());
}

void SceneCircular::timerEvent(QTimerEvent *)
{
    circularItem->moveBy(xStep, yStep); //相对移动

    if(circularItem->collidesWithItem(lineLeft) || circularItem->collidesWithItem(lineRight))
    {
        xStep = -xStep;
    }
    if(circularItem->collidesWithItem(lineTop) || circularItem->collidesWithItem(lineBottom))
    {
        yStep = -yStep;
    }
}

void SceneCircular::BackToOrigin()
{
    circularItem->setRect(QRectF(itemLeftPos, itemSize));
}

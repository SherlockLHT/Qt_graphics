#include "scenetriangle.h"

SceneTriangle::SceneTriangle():
    sceneLeftTopPos(QPointF(-100, -100)), sceneSize(QSizeF(300, 200)),updateTime(100),
    itemTopPos(QPoint(0, 0)), itemBottomPos(QPoint(0, 50)), itemLeftPos(QPoint(-50, 25)),
    xStep(5), yStep(4)
{
    setSceneRect(QRectF(sceneLeftTopPos, sceneSize));   //场景大小

    triItem = new QGraphicsPolygonItem; //新建多边形图形项
    triItem->setBrush(Qt::blue);

    QVector<QPoint> polygon_point;
    polygon_point.append(itemTopPos);   //加入三角形三个角坐标
    polygon_point.append(itemBottomPos);
    polygon_point.append(itemLeftPos);

    QPolygon polygon(polygon_point);
    triItem->setPolygon(polygon);
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
    addItem(triItem);
    addItem(lineLeft);
    addItem(lineRight);
    addItem(lineTop);
    addItem(lineBottom);
}

SceneTriangle::~SceneTriangle()
{
    delete triItem;
    delete lineLeft;
    delete lineRight;
    delete lineTop;
    delete lineBottom;

    lineLeft    = NULL;
    lineRight   = NULL;
    lineTop     = NULL;
    lineBottom  = NULL;
    triItem     = NULL;
}

void SceneTriangle::AddSteps()
{
    xStep = (xStep < 45)? xStep + 1.0: xStep;
    yStep = (yStep < 35)? yStep + 1.0: yStep;

    qDebug()<<"x step:"<<xStep;
    qDebug()<<"y step:"<<yStep;
}

void SceneTriangle::ReduceSteps()
{
    xStep = xStep > -45? xStep - 1: xStep;
    yStep = yStep > -35? yStep - 1: yStep;

    qDebug()<<"x step:"<<xStep;
    qDebug()<<"y step:"<<yStep;
}

void SceneTriangle::StartMove()
{
    if( !isMoving )
    {
        timerID = startTimer(updateTime);
        isMoving = true;
    }
}

void SceneTriangle::StopMove()
{
    if( isMoving )
    {
        killTimer(timerID);
        isMoving = false;
    }
}

void SceneTriangle::SetSceneSize(const QSize &size)
{
    //setSceneRect(-300, -300, size.width(), size.height());
}

void SceneTriangle::timerEvent(QTimerEvent *)
{
    triItem->moveBy(xStep, yStep);  //相对移动

    if(triItem->collidesWithItem(lineLeft) || triItem->collidesWithItem(lineRight))
    {
        xStep = -xStep;
    }
    if(triItem->collidesWithItem(lineTop) || triItem->collidesWithItem(lineBottom))
    {
        yStep = -yStep;
    }
}

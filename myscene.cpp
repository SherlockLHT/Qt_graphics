#include "myscene.h"

MyScene::MyScene(ItemType type):
    sceneLeftTopPos(QPointF(-100, -100)), sceneSize(QSizeF(400, 300)),
    itemLeftPos(QPoint(0, 0)), itemSize(QSizeF(50, 50)),
    itemTopPos(QPoint(50, 25)), itemBottomPos(QPoint(0, 50)),
    shapeItem(NULL), isStart(true), xStep(1), yStep(1), timeMsec(500)
{
    Initlize();

    switch(type)
    {
    case RectItem:
    {
        QGraphicsRectItem* item = new QGraphicsRectItem();
        item->setRect(QRectF(itemLeftPos, itemSize));
        item->setBrush(Qt::red);
        shapeItem = dynamic_cast<QGraphicsItem*> (item);
        item = NULL;
        break;
    }
    case CircularItem:
    {
        QGraphicsEllipseItem* item = new QGraphicsEllipseItem();
        item->setRect(QRectF(itemLeftPos, itemSize));
        item->setBrush(Qt::green);
        shapeItem = dynamic_cast<QGraphicsItem*> (item);
        item = NULL;
        break;
    }
    case TriangleItem:
    {
        QGraphicsPolygonItem* item = new QGraphicsPolygonItem();
        QVector<QPoint> polygon_point;
        polygon_point.append(itemTopPos);   //加入三角形三个角坐标
        polygon_point.append(itemBottomPos);
        polygon_point.append(itemLeftPos);

        QPolygon polygon(polygon_point);
        item->setPolygon(polygon);
        item->setBrush(Qt::blue);
        shapeItem = dynamic_cast<QGraphicsItem*> (item);
        item = NULL;
        break;
    }
    default:
        break;
    }

    addItem(shapeItem);
}

MyScene::~MyScene()
{
    delete shapeItem;
    delete lineLeft;
    delete lineRight;
    delete lineTop;
    delete lineBottom;
}

void MyScene::Initlize()
{
    setSceneRect(QRectF(sceneLeftTopPos, sceneSize));   //场景大小
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
    addItem(lineLeft);
    addItem(lineRight);
    addItem(lineTop);
    addItem(lineBottom);

    radomDirection.append(-1);
    radomDirection.append(1);

    connect(&itemMoveTimer, SIGNAL(timeout()), this, SLOT(Moving()));
}

void MyScene::DeleteItems()
{
    itemMoveTimer.stop();

    removeItem(shapeItem);
}

void MyScene::Moving()
{
    shapeItem->moveBy(xStep, yStep);  //相对移动

    //碰撞检测
    if(shapeItem->collidesWithItem(lineLeft) || shapeItem->collidesWithItem(lineRight))
    {
        xStep = -xStep;
    }
    if(shapeItem->collidesWithItem(lineTop) || shapeItem->collidesWithItem(lineBottom))
    {
        yStep = -yStep;
    }
}

void MyScene::StartMove()
{
    if( isStart )    //从初始位置开始移动，随机选取方向
    {
        RandomDirection();
        isStart = false;
    }
    if( !itemMoveTimer.isActive() ) //未在移动
    {
        itemMoveTimer.start(timeMsec);
    }
}

void MyScene::PauseMove()
{
    itemMoveTimer.stop();
}

void MyScene::StopMove()
{
    itemMoveTimer.stop();
    shapeItem->setX(itemLeftPos.x());
    shapeItem->setY(itemLeftPos.y());
    isStart = true;
}

void MyScene::AddSpeed()
{
    if( itemMoveTimer.isActive() && timeMsec > 1) //在移动
    {
        itemMoveTimer.stop();
        timeMsec = timeMsec / 2;
        itemMoveTimer.start(timeMsec);
    }
    qDebug()<<"Time Msec:"<<timeMsec;
}

void MyScene::ReduceSpeed()
{
    if( itemMoveTimer.isActive() && timeMsec < 1000) //在移动
    {
        itemMoveTimer.stop();
        timeMsec = timeMsec * 2;
        itemMoveTimer.start(timeMsec);
    }
    qDebug()<<"Time Msec:"<<timeMsec;
}

void MyScene::RandomDirection()
{
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));

    xStep = radomDirection.at(qrand()%2);
    yStep = radomDirection.at(qrand()%2);

    qDebug()<<"X Step:"<<xStep;
    qDebug()<<"Y Step:"<<yStep;
}

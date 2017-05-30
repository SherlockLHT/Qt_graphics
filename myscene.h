#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsLineItem>
#include <QTimerEvent>
#include <QtGlobal>
#include <QPointF>
#include <QPoint>
#include <QSizeF>
#include <QVector>
#include <QPolygon>
#include <QTimer>
#include <QTime>
#include <QDebug>

typedef enum _itemType{
    RectItem,
    CircularItem,
    TriangleItem
}ItemType;

class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MyScene(ItemType type = RectItem);
    ~MyScene();

    void Initlize();

    /**
     * @brief 删除图形项
     */
    void DeleteItems();

    /**
     * @brief 图形项开始移动
     */
    void StartMove();

    /**
     * @brief 图形项暂停移动
     */
    void PauseMove();

    /**
     * @brief 图形项停止移动，并回复原位
     */
    void StopMove();

    /**
     * @brief 移动速度增加为原来的2倍
     */
    void AddSpeed();

    /**
     * @brief 移动速度减小为原来的1/2
     */
    void ReduceSpeed();

    /**
     * @brief 生成随机方向
     */
    void RandomDirection();

public slots:

    /**
     * @brief 图形项移动
     */
    void Moving();

private:
    QGraphicsItem*  shapeItem;  //图形项指针

    QGraphicsLineItem* lineLeft;    //场景左侧线
    QGraphicsLineItem* lineRight;   //场景右侧线
    QGraphicsLineItem* lineTop;     //场景上部线
    QGraphicsLineItem* lineBottom;  //场景下部线

    QPointF sceneLeftTopPos;        //场景左上角坐标
    QSizeF sceneSize;               //场景大小

    QPoint itemLeftPos;    //item位置
    QSizeF itemSize;        //item大小

    QPoint itemTopPos;      //item位置，用于三角形
    QPoint itemBottomPos;

    QVector<int> radomDirection;
    bool isStart;       //刚开始运动
    double xStep;   //步进
    double yStep;

    QTimer itemMoveTimer;
    int timeMsec;
};

#endif // MYSCENE_H

#ifndef SCENECIRCULAR_H
#define SCENECIRCULAR_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QWidget>
#include <QGraphicsLineItem>
#include <QPointF>
#include <QSizeF>
#include <QRectF>
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>
#include <QDebug>
#include <QThread>

class SceneCircular : public QGraphicsScene
{
public:
    SceneCircular();
    ~SceneCircular();

public:
    /*
     * @bref    item移动
     */
    void StartMove();
    /*
     * @bref    停止item移动
     */
    void StopMove();

    /*
     * @bref    增加移动步进
     */
    void AddSteps();
    /*
     * @bref    减小移动步进
     */
    void ReduceSteps();

    /*
     * @bref    回到起始点
     */
    void BackToOrigin();

    /*
     * @bref    设置场景大小
     */
    void SetSceneSize( const QSize& size );

protected:
    void timerEvent(QTimerEvent*);

private:
    QGraphicsEllipseItem* circularItem;

    QGraphicsLineItem* lineLeft;    //场景左侧线
    QGraphicsLineItem* lineRight;   //场景右侧线
    QGraphicsLineItem* lineTop;     //场景上侧线
    QGraphicsLineItem* lineBottom;  //场景下侧线

    QPointF sceneLeftTopPos;        //场景左上角坐标
    QSizeF sceneSize;               //场景大小

    int timerID;
    int updateTime;

    qreal xStep;
    qreal yStep;

    QPointF itemLeftPos;
    QSizeF itemSize;

    bool isMoving;  //正在移动
};

#endif // SCENECIRCULAR_H

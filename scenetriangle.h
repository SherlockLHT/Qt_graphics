#ifndef SCENETRIANGLE_H
#define SCENETRIANGLE_H

#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QPolygon>
#include <QVector>
#include <QPointF>
#include <QPoint>
#include <QSizeF>
#include <QRectF>
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>
#include <QDebug>

class SceneTriangle : public QGraphicsScene
{
public:
    SceneTriangle();
    ~SceneTriangle();

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
     * @bref    设置场景大小
     * @note    暂时无用
     */
    void SetSceneSize( const QSize& size );

protected:
    void timerEvent(QTimerEvent*);

private:
    QGraphicsPolygonItem* triItem;    //圆形图形项

    QGraphicsLineItem* lineLeft;    //场景左侧线
    QGraphicsLineItem* lineRight;   //场景右侧线
    QGraphicsLineItem* lineTop;     //场景上部线
    QGraphicsLineItem* lineBottom;  //场景下部线

    QPointF sceneLeftTopPos;    //场景坐标
    QSizeF sceneSize;           //场景大小

    int timerID;        //计时器ID
    int updateTime;     //计时器更新频率

    qreal xStep;    //步进
    qreal yStep;

    QPoint itemTopPos;    //item位置
    QPoint itemBottomPos;
    QPoint itemLeftPos;

    bool isMoving;  //正在移动
};

#endif // SCENETRIANGLE_H

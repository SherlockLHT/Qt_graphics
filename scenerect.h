#ifndef SCENERECT_H
#define SCENERECT_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QPointF>
#include <QSizeF>
#include <QRectF>
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>
#include <QDebug>

class SceneRect : public QGraphicsScene
{
public:
    SceneRect();
    ~SceneRect();

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
     */
    void SetSceneSize( const QSize& size );

protected:
    void timerEvent(QTimerEvent*);

private:
    QGraphicsRectItem* rectItem;

    QGraphicsLineItem* lineLeft;    //场景左侧线
    QGraphicsLineItem* lineRight;
    QGraphicsLineItem* lineTop;
    QGraphicsLineItem* lineBottom;

    int timerID;
    QPointF sceneLeftTopPos;
    QSizeF sceneSize;

    int updateTime;

    qreal xStep;
    qreal yStep;

    QPointF itemLeftPos;
    QSizeF itemSize;

};

#endif // SCENERECT_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QTimerEvent>
#include <QTimer>
#include <QResizeEvent>

#include "myscene.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void Init();
    void UnInit();

public slots:
    void OnStartButton();

    void OnPauseButton();

    void OnStopButton();

    void OnQuickButton();

    void OnSlowButton();

    void OnRectButton();

    void OnCircularButton();

    void OnTirangleButton();

private:
    MyScene* rectScene;     //矩形项场景
    MyScene* circularScene; //圆形场景
    MyScene* triangleScene; //三角形场景

    MyScene* currentScene;  //当前显示的场景

};

#endif // MAINWINDOW_H

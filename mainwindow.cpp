#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Init();

    OnRectButton();
}

MainWindow::~MainWindow()
{
    UnInit();

    delete ui;
}

void MainWindow::Init()
{
    circuScene = NULL;
    rectScene = NULL;
    tirScene = NULL;

    connect(ui->pushbutton_start, SIGNAL(clicked(bool)), this, SLOT(OnStartButton()));

    connect(ui->pushButton_pause, SIGNAL(clicked(bool)), this, SLOT(OnPauseButton()));

    connect(ui->pushButton_stop, SIGNAL(clicked(bool)), this, SLOT(OnStopButton()));

    connect(ui->pushButton_quick, SIGNAL(clicked(bool)), this, SLOT(OnQuickButton()));

    connect(ui->pushButton_slow, SIGNAL(clicked(bool)), this, SLOT(OnSlowButton()));

    connect(ui->pushButton_rect, SIGNAL(clicked(bool)), this, SLOT(OnRectButton()));

    connect(ui->pushButton_circu, SIGNAL(clicked(bool)), this, SLOT(OnCircularButton()));

    connect(ui->pushButton_tria, SIGNAL(clicked(bool)), this, SLOT(OnTirangleButton()));
}

void MainWindow::UnInit()
{

}

void MainWindow::OnStartButton()
{

}

void MainWindow::OnPauseButton()
{

}

void MainWindow::OnStopButton()
{

}

void MainWindow::OnQuickButton()
{

}

void MainWindow::OnSlowButton()
{

}

void MainWindow::OnRectButton()
{
    if( NULL != circuScene )
    {
        delete circuScene;
        circuScene = NULL;
    }
    if( NULL != tirScene )
    {
        delete tirScene;
        tirScene = NULL;
    }

    rectScene = new sceneRect;
    ui->graphicsView->setScene(rectScene);
}

void MainWindow::OnTirangleButton()
{
    if( NULL != circuScene )
    {
        delete circuScene;
        circuScene = NULL;
    }
    if( NULL != rectScene )
    {
        delete circuScene;
        circuScene = NULL;
    }

    tirScene = new sceneTriangle;
    ui->graphicsView->setScene(tirScene);
}

void MainWindow::OnCircularButton()
{
    if( NULL != rectScene )
    {
        delete rectScene;
        rectScene = NULL;
    }
    if( NULL != tirScene )
    {
        delete tirScene;
        tirScene = NULL;
    }

    circuScene = new sceneCircular;
    ui->graphicsView->setScene(circuScene);
}

void MainWindow::timerEvent(QTimerEvent *event)
{

}

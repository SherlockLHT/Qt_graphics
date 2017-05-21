#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    circuScene(NULL), rectScene(NULL), tirScene(NULL)
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
    delete circuScene;
    delete tirScene;
    delete rectScene;

    circuScene  = NULL;
    rectScene   = NULL;
    tirScene    = NULL;
}

void MainWindow::OnStartButton()
{
    if( rectScene )
    {
        rectScene->StartMove();
    }
    else if(circuScene)
    {
        circuScene->StartMove();
    }
    else if(tirScene)
    {
        tirScene->StartMove();
    }
}

void MainWindow::OnPauseButton()
{
    if( rectScene )
    {
        rectScene->StopMove();
    }
    else if(circuScene)
    {
        circuScene->StopMove();
    }
    else if(tirScene)
    {
        tirScene->StopMove();
    }
}

void MainWindow::OnStopButton()
{
    if( rectScene )
    {
        delete rectScene;
        rectScene = NULL;
    }
    else if(circuScene)
    {
        delete circuScene;
        rectScene = NULL;
    }
    else if(tirScene)
    {
        delete tirScene;
        tirScene = NULL;
    }
}

void MainWindow::OnQuickButton()
{
    if( rectScene )
    {
        rectScene->AddSteps();
    }
    else if(circuScene)
    {
        circuScene->AddSteps();
    }
    else if(tirScene)
    {
        tirScene->AddSteps();
    }
}

void MainWindow::OnSlowButton()
{
    if( rectScene )
    {
        rectScene->ReduceSteps();
    }
    else if(circuScene)
    {
        circuScene->ReduceSteps();
    }
    else if(tirScene)
    {
        tirScene->ReduceSteps();
    }
}

void MainWindow::OnRectButton()
{
    delete circuScene;
    circuScene = NULL;

    delete tirScene;
    tirScene = NULL;

    if( NULL == rectScene )
    {
        rectScene = new SceneRect;
        ui->graphicsView->setScene(rectScene);
    }
}

void MainWindow::OnTirangleButton()
{
    delete circuScene;
    circuScene = NULL;

    delete rectScene;
    rectScene = NULL;

    if( NULL == tirScene )
    {
        tirScene = new SceneTriangle;
        ui->graphicsView->setScene(tirScene);
    }
}

void MainWindow::OnCircularButton()
{
    delete rectScene;
    rectScene = NULL;

    delete tirScene;
    tirScene = NULL;

    if(NULL == circuScene )
    {
        circuScene = new SceneCircular;
        ui->graphicsView->setScene(circuScene);
    }
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    if( rectScene )
    {
        rectScene->SetSceneSize(ui->graphicsView->size());
    }
}

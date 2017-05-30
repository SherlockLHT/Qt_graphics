#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Init();
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

    rectScene = new MyScene(RectItem);
    circularScene = new MyScene(CircularItem);
    triangleScene = new MyScene(TriangleItem);

    currentScene = rectScene;
    ui->graphicsView->setScene(currentScene);
}

void MainWindow::UnInit()
{
    rectScene->DeleteItems();
    circularScene->DeleteItems();
    triangleScene->DeleteItems();

    delete rectScene;
    delete circularScene;
    delete triangleScene;
}

void MainWindow::OnStartButton()
{
    currentScene->StartMove();
}

void MainWindow::OnPauseButton()
{
    currentScene->PauseMove();
}

void MainWindow::OnStopButton()
{
    currentScene->StopMove();
}

void MainWindow::OnQuickButton()
{
    currentScene->AddSpeed();
}

void MainWindow::OnSlowButton()
{
    currentScene->ReduceSpeed();
}

void MainWindow::OnRectButton()
{
    currentScene = rectScene;
    ui->graphicsView->setScene(currentScene);
}

void MainWindow::OnTirangleButton()
{
    currentScene = triangleScene;
    ui->graphicsView->setScene(currentScene);
}

void MainWindow::OnCircularButton()
{
    currentScene = circularScene;
    ui->graphicsView->setScene(currentScene);
}

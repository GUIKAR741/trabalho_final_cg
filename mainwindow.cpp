#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, ui->canvas, &Canvas::idleGL);
    timer->start(1000/60);
    ui->canvas->setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
// #include 

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/image/God2.png"));

    ui->label->setPixmap(QPixmap(":/image/God2.png"));

    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::Cal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Cal()
{
    ui->lineEdit->setText("Hello world");
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += i;
    }
    qDebug() << sum;
}
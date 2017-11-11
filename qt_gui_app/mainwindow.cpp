#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->photo ->setPixmap(QPixmap(":/resoures/images/touxiang.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;

}

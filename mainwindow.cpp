#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task1.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_show(QString login)
{
    this->show();
}

void MainWindow::on_pushButton_Exit_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_Task1_clicked()
{
    task1_ui = new task1;
    task1_ui->show();
}


void MainWindow::on_pushButton_Task2_clicked()
{
    task2_ui = new task2;
    task2_ui->show();
}


void MainWindow::on_pushButton_Task3_clicked()
{
    task3_ui = new task3;
    task3_ui->show();
}


void MainWindow::on_pushButton_Task4_clicked()
{
    task4_ui = new task4;
    task4_ui->show();
}


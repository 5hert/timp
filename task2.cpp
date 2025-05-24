#include "task2.h"
#include "ui_task2.h"

task2::task2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::task2)
{
    ui->setupUi(this);
}

task2::~task2()
{
    delete ui;
}

void task2::on_pushButton_Task2_Cancel_clicked()
{
    this->close();
}


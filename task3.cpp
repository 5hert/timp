#include "task3.h"
#include "ui_task3.h"

task3::task3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::task3)
{
    ui->setupUi(this);
}

task3::~task3()
{
    delete ui;
}

void task3::on_pushButton_Task3_Cancel_clicked()
{
    this->close();
}



#include "task4.h"
#include "ui_task4.h"

task4::task4(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::task4)
{
    ui->setupUi(this);
}

task4::~task4()
{
    delete ui;
}

void task4::on_pushButton_Task4_Cancel_clicked()
{
    this->close();
}


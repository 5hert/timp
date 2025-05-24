#include "authregform.h"
#include "ui_authregform.h"
#include "functions_for_client.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    change_type_to_reg(false);
}

void AuthRegForm::change_type_to_reg(bool is_reg)
{
    ui->label_PasswordAgain->setVisible(is_reg);
    ui->label_Email->setVisible(is_reg);
    ui->lineEdit_PasswordAgain->setVisible(is_reg);
    ui->lineEdit_Email->setVisible(is_reg);
    ui->pushButton_Reg->setVisible(is_reg);

    ui->pushButton_Auth->setVisible(!is_reg);

    ui->pushButton_Change->setText(is_reg? "to Auth" : "to Reg");
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushButton_Change_clicked()
{
    change_type_to_reg(!ui->label_Email->isVisible());
}


void AuthRegForm::on_pushButton_Auth_clicked()
{
    if(auth(ui->lineEdit_Login->text(),ui->lineEdit_Password->text()))
    {
        emit auth_ok(ui->lineEdit_Login->text());
        this->close();
    }
    else
        clear();
}

void AuthRegForm::clear()
{
    ui->lineEdit_Login->setText("");
    ui->lineEdit_Password->setText("");
    ui->lineEdit_PasswordAgain->setText("");
    ui->lineEdit_Email->setText("");
}
void AuthRegForm::on_pushButton_Reg_clicked()
{
    if(ui->lineEdit_Password->text() != ui->lineEdit_PasswordAgain->text())
        this->clear();
    else
    {
        if(reg(ui->lineEdit_Login->text(),ui->lineEdit_Password->text(),ui->lineEdit_Email->text()))
        {
            emit auth_ok(ui->lineEdit_Login->text());
            this->close();
        }
        else
            this->clear();

    }
}


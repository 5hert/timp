#include "formsmanager.h"
#include "clientapi.h"

FormsManager::FormsManager(QWidget *parent)
    : QMainWindow(parent)
{
    this->current_auth = new AuthRegForm();
    this->current_auth->show();
    this->main_form = new MainWindow();

    // Формальная "проверка" синглтона
    ClientAPI* api = ClientAPI::getInstance();
    qDebug() << "ClientAPI создан. Состояние подключения:" << api->isConnected();

    connect(current_auth,&AuthRegForm::auth_ok,main_form,&MainWindow::slot_show);
}

FormsManager::~FormsManager() {}

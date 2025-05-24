#include <QCoreApplication>
#include "clientapi.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<ClientAPI::getInstance()->querry_to_server("asddff12345");
    return a.exec();
}

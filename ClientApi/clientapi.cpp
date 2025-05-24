#include "clientapi.h"

ClientAPI* ClientAPI::p_instance;
SingletonDestroyer ClientAPI::destroyer;

SingletonDestroyer::~SingletonDestroyer()
{
    delete p_instance;
}

void SingletonDestroyer::initialize(ClientAPI * p)
{
    p_instance = p;
};

ClientAPI::ClientAPI(QObject *parent)
{
    mTcpSocket = new QTcpSocket(this);

    connect(this->mTcpSocket, &QTcpSocket::disconnected,
           this, &ClientAPI::slotServerDisconnection);
    mTcpSocket->connectToHost("127.0.0.1",33333);
    mTcpSocket->waitForReadyRead();
    QByteArray array;
    while(mTcpSocket->bytesAvailable()>0)
    {
        array.append(mTcpSocket->readAll());
    }
    qDebug() << array;
}

ClientAPI::~ClientAPI()
{
    this->mTcpSocket->close();
}

ClientAPI* ClientAPI::getInstance(){
    if (!p_instance)
    {
        p_instance = new ClientAPI();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void ClientAPI::slotServerDisconnection()
{
    mTcpSocket->close();
    //emit disconnected();
}

QByteArray ClientAPI::querry_to_server(QString msg)
{
    mTcpSocket->write(msg.toUtf8());
    mTcpSocket->waitForReadyRead();
    QByteArray array;
    while(mTcpSocket->bytesAvailable()>0)
    {
        array.append(mTcpSocket->readAll());
    }
    return array;
}



bool ClientAPI::isConnected()
{
    return mTcpSocket->state() == QTcpSocket::ConnectedState;
}

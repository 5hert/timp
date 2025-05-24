#include "functions_for_client.h"
#include <QString>
#include "clientapi.h"

//functions_for_client::functions_for_client() {}
bool auth(QString login,QString password)
{
    //запрос на сервер
    //if(ClientAPI::getInstance()->querry_to_server("auth&login&password")=="auth+")
    if(login == "user" && password == "123")
        return true;
    else
        return false;
}
bool reg(QString login,QString password,QString email)
{
    //запрос на сервер регистрации и авторизации
    //if(ClientAPI::getInstance()->querry_to_server("reg&login&password")=="reg+")
    if(login != "user" || password != "123")
        return true;
    else
        return false;
}

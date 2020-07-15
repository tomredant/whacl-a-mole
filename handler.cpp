#include "handler.h"

handler::handler(QObject *parent) : QObject(parent)
{

}

handler * handler::hand =new handler;

handler * handler::getInstance()
{
    return hand;
}
void handler::addScore()
{
    emit whackmole();//发送打到地鼠的信号
}

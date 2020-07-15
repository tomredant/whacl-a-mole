#include "myitem.h"
#include<QPixmap>
#include<QDebug>
#include"handler.h"
#include<QCursor>
myItem::myItem()
{
    this->setPixmap(QPixmap(":/backgroud/pic/mole.png"));
    this->start=false;
    this->mole=false;
    this->setCursor(QCursor(QPixmap(":/hammer/pic/hammer_1.png")));
}

void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/hammer/pic/hammer_2.png")));
    if(this->isStart()){
        handler * hand = handler::getInstance();
    if(this->isMole()){
       hand->addScore();
       this->setPixmap(QPixmap(":/mole/pic/mole_3.png"));
       this->mole=false;
    }
    }
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    this->setCursor(QCursor(QPixmap(":/hammer/pic/hammer_1.png")));
}

void myItem::setMole(bool mole)
{
    this->mole =mole;
}

bool myItem::isMole()
{
    return this->mole;
}

void myItem::setStart(bool start)
{
 this->start=start;
}
bool myItem::isStart()
{
    return this->start;
}

#include "myitem.h"
#include<QPixmap>
#include<QDebug>
#include"handler.h"
#include "globals.h"
#include<QCursor>
myItem::myItem()
{
    this->setPixmap(QPixmap(":/backgroud/pic/mole.png"));
    this->start=false;
    this->mole=0;
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
        Handler * hand = Handler::getInstance();
        hand->playSound();
        if(this->isMole()== MOLE){
            hand->addScore();
            this->setPixmap(QPixmap(":/mole/pic/mole_3.png"));
            this->mole=NO_MOLE;
        }

        if(this->isMole()== FAKE_MOLE){
            hand->subtractScore();
            this->setPixmap(QPixmap(":/mole/pic/mole_5.png"));
            this->mole=NO_MOLE;
        }
    }
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    this->setCursor(QCursor(QPixmap(":/hammer/pic/hammer_1.png")));
}

void myItem::setMole(int mole)
{
    this->mole =mole;
}

int myItem::isMole()
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

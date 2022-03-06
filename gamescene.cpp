#include "gamescene.h"
#include<stdlib.h>
#include <QDateTime>
#include "globals.h"
#include "math.h"
gameScene::gameScene(QObject *parent) : QGraphicsScene(parent)
{
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i] = new myItem;
        this->item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }
    this->p_timer=new QTimer;
    connect(this->p_timer,SIGNAL(timeout()),this,SLOT(showMole()));

    this->p_timerFast=new QTimer;
    connect(this->p_timerFast,SIGNAL(timeout()),this,SLOT(updateGameTime()));
    m_startTime = 0;
}
void gameScene::showMole()
{
    int count = 1;//rand()%3+1;
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setPic(":/backgroud/pic/mole.png");
        this->item[i]->setMole(0);
    }
    for(i=0;i<count;i++)
    {
        int index = rand()%16;
        if((rand()%2)==0) {
            this->item[index]->setPic(":/mole/pic/mole_2.png");
            this->item[index]->setMole(1);
        } else {
            this->item[index]->setPic(":/mole/pic/mole_4.png");
            this->item[index]->setMole(2);
        }
    }
}

void gameScene::updateGameTime() {
    int timeLeft = GAME_DURATION -floor((QDateTime::currentMSecsSinceEpoch()-m_startTime)/1000);
    emit notifyGameTime(timeLeft);
    if(timeLeft <=0) {
        for(int i=0;i<16;i++)
        {
            this->item[i]->setPic(":/backgroud/pic/mole.png");
            this->item[i]->setMole(0);
        }
        this->p_timer->stop();
        this->p_timerFast->stop();
    }
}
void gameScene::startGame()
{

    m_startTime=QDateTime::currentMSecsSinceEpoch();

    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setStart(true);
    }
    this->p_timer->start(800);
    this->p_timerFast->start(100);
}




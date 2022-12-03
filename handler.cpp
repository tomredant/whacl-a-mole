#include "handler.h"
#include <QThread>
#include "soundplayer.h"
Handler::Handler(QObject *parent) : QObject(parent)
{

    m_musicThread = new QThread();
    m_musicThread->setObjectName("Audio player thread");
    m_musicThread->start();
    m_player = new SoundPlayer();
    m_player->moveToThread(m_musicThread);



    m_musicThread2 = new QThread();
    m_musicThread2->setObjectName("Audio player thread");
    m_musicThread2->start();
    m_player2 = new SoundPlayer();
    m_player2->moveToThread(m_musicThread2);
}

Handler * Handler::hand =new Handler;

Handler * Handler::getInstance()
{
    return hand;
}
void Handler::addScore()
{
    emit whackMole();
    m_player2->interruptEventSound();
    QMetaObject::invokeMethod(m_player2, "playWinSound");
}

void Handler::subtractScore()
{
    emit whackWrongMole();
    m_player2->interruptEventSound();
    QMetaObject::invokeMethod(m_player2, "playFailSound");
}


void Handler::playSound() {
    m_player->interruptEventSound();
    QMetaObject::invokeMethod(m_player, "playEventSound");
}

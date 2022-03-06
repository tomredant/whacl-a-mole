#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
class QThread;
class SoundPlayer;
class Handler : public QObject
{
    Q_OBJECT
public:
    static Handler *getInstance();
    void addScore();
    void subtractScore();

private:
    explicit Handler(QObject *parent = nullptr);

signals:
    void whackMole();
    void whackWrongMole();

public slots:
    void playSound();
private:
    static Handler * hand;
    SoundPlayer* m_player;
    QThread* m_musicThread;

    SoundPlayer* m_player2;
    QThread* m_musicThread2;
};

#endif // HANDLER_H

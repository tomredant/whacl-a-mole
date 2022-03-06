#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>

class SoundPlayer : public QObject
{
    Q_OBJECT
public:
    SoundPlayer();
    void interruptEventSound();
    void setEnableMusic(bool enableMusic);
    bool musicEnabled();
public slots:
    bool playMusic();
    bool playEventSound();
    bool playWinSound();
    bool playFailSound();

signals:

private:
    bool m_interruptEventSound = false;
    bool m_enableMusic = true;
};

#endif // SOUNDPLAYER_H

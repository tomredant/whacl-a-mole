#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"handler.h"
#include <QThread>
#include "soundplayer.h"
#include "showlicense.h"
#include "globals.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<QToolBar *> allToolBars = findChildren<QToolBar *>();
    foreach(QToolBar *tb, allToolBars) {
        removeToolBar(tb);
        delete tb;
    }
    this->sc = new gameScene;
    this->ui->graphicsView->setScene(sc);
    setStyleSheet("QGraphicsView { background: rgb(255, 228, 49);border:0px }");
    setStyleSheet("QMainWindow { background: rgb(255, 228, 49);}");
    //QPushButton{ background-color: rgb(255, 228, 49);}
    //setStyleSheet("");



    this->ui->graphicsView->setFrameShape(QFrame::NoFrame);
    this->ui->gridLayout->setMargin(0);
    this->ui->statusBar->hide();


    connect(this->ui->muteButton,SIGNAL(clicked()), this, SLOT(toggleMusic()));
    connect(this->ui->aboutButton,SIGNAL(clicked()), this, SLOT(clickAbout()));
    connect(this->sc,SIGNAL(notifyGameTime(int)), this, SLOT(updateGameTime(int)));


    this->sc->startGame();
    this->score=0;
    this->ui->score->setText("<font color=\"#FFE431\">" + QString::number(this->score) + "</font>");
    //this->ui->time->setText("<font color=\"#FFE431\">" + QString::number(GAME_DURATION) + "</font>");

    connect(this->ui->restartButton,&QPushButton::clicked,[=]()
    {
        this->sc->startGame();
        this->score=0;
        this->ui->score->setText("<font color=\"#FFE431\">" + QString::number(this->score) + "</font>");

    });
    Handler * hand=Handler::getInstance();
    connect(hand,SIGNAL(whackMole()),this,SLOT(updateScore()));
    connect(hand,SIGNAL(whackWrongMole()),this,SLOT(updateScoreNegative()));

    m_musicThread = new QThread();
    m_musicThread->setObjectName("Audio player thread");
    m_musicThread->start();
    m_player = new SoundPlayer();
    m_player->moveToThread(m_musicThread);
    QMetaObject::invokeMethod(m_player, "playMusic");

}


void MainWindow::updateGameTime(int time) {
    this->ui->time->setText("<font color=\"#FFE431\">" + QString::number(time) + "</font>");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateScore(){
    (this->score)++;
    this->ui->score->setText("<font color=\"#FFE431\">" + QString::number(this->score) + "</font>");
}


void MainWindow::updateScoreNegative(){
    if(this->score > 0)
        (this->score)--;
    this->ui->score->setText("<font color=\"#FFE431\">" + QString::number(this->score) + "</font>");
}

void MainWindow::toggleMusic() {
    m_player->setEnableMusic(!m_player->musicEnabled());
    if(m_player->musicEnabled())
        this->ui->muteButton->setIcon(QIcon(":/pic/icon_sound.png"));
    else
        this->ui->muteButton->setIcon(QIcon(":/pic/icon_mute.png"));

}

void MainWindow::clickAbout() {
    std::vector<std::string> libs;
    libs.push_back("Whacl-a-mole#" + QObject::tr("Original Game whacl-a-mole made by yangjianguo66 注释 (https://github.com/yangjianguo66/whacl-a-mole), modifications and integrations of purchased artwork by Hammer-IMS nv, \nSource Code:\nhttps://github.com/tomredant/whacl-a-mole").toStdString() + "#gpl-3.0");
    libs.push_back(R"MYSTRING(PortAudio V19.6.0-devel##/*
                  * PortAudio Portable Real-Time Audio Library
                  * Latest Version at: http://www.portaudio.com
                  *
                  * Copyright (c) 1999-2008 Phil Burk and Ross Bencina
                  *
                  * Permission is hereby granted, free of charge, to any person obtaining
                  * a copy of this software and associated documentation files
                  * (the "Software"), to deal in the Software without restriction,
                  * including without limitation the rights to use, copy, modify, merge,
                  * publish, distribute, sublicense, and/or sell copies of the Software,
                  * and to permit persons to whom the Software is furnished to do so,
                  * subject to the following conditions:
                  *
                  * The above copyright notice and this permission notice shall be
                  * included in all copies or substantial portions of the Software.
                  *
                  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
                  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
                  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
                  * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
                  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
                  * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
                  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
                  */

                 /*
                  * The text above constitutes the entire PortAudio license; however,
                  * the PortAudio community also makes the following non-binding requests:
                  *
                  * Any person wishing to distribute modifications to the Software is
                  * requested to send the modifications to the original developer so that
                  * they can be incorporated into the canonical version. It is also
                  * requested that these non-binding requests be included along with the
                  * license above.
                  */


                 PortAudio is a portable audio I/O library designed for cross-platform
                 support of audio. It uses either a callback mechanism to request audio
                 processing, or blocking read/write calls to buffer data between the
                 native audio subsystem and the client. Audio can be processed in various
                 formats, including 32 bit floating point, and will be converted to the
                 native format internally.
)MYSTRING");
    libs.push_back("Qt5.15.3#Source files can be obtained from http://www.qt.io.#lgpl-3.0");
    libs.push_back("MinGW-W64-builds-4.3.5##MinGW-w64");
    libs.push_back("libstdc++-6##gpl-3.0_runtime_exception");
    libs.push_back(R"MYSTRING(Artwork and Audio##
Artwork purchased from Shutterstock under the terms of a Standard License for Hammer-IMS nv.
Shutterstock image references:

777735502
1918409366
1483995575
1924474265

Audio from Audiojungle under the terms of a commercial license for Hammer-IMS nv.

https://audiojungle.net/item/metal-impact/32309247 (SFX (Single Use))
https://audiojungle.net/item/failed/3193419 (SFX (Single Use))
https://audiojungle.net/item/coins-game/35941516 (SFX (Single Use))
https://audiojungle.net/item/game-play/25351031 (Music Standard License)

)MYSTRING");

    populateLicenseDialog(libs);
    setCustomLicenseMainMessage("This game was made possible by the existence of few third-party libraries and resources, which are used in this game. A complete list is shown in the tabs below.");
    setCustomLicenseLogo(":/pic/hammer.ico");
    setCustomLicenseAcceptText("Accept");
    setCustomLicenseRejectText("Reject");
    setCustomLicenseWindowTitleText("About");
    showLicenseDialog();
    if(!waitLicenseDialogAccepted())
        return;
}


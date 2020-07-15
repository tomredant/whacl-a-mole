#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"handler.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new gameScene;
    this->ui->graphicsView->setScene(sc);
    this->ui->welcome_scene->show();
    connect(this->ui->startBTN,&QPushButton::clicked,[=]()
    {
        this->ui->welcome_scene->hide();
        this->sc->startGame();
    });
//    connect(this->ui->startBTN,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->pauseBTN,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    this->score=0;
    handler * hand=handler::getInstance();
    connect(hand,SIGNAL(whackmole()),this,SLOT(updateScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateScore(){
    this->score+=10;
    this->ui->lcdNumber->display(this->score);
}

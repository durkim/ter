/**
 * \file window.cpp
 * \brief représente l'interface graphique de l'application
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 *
 *
 */

#include "Window.h"
#include <QGridLayout>
#include <QApplication>
#include <iostream>
#include <QFileDialog>

Window::Window() {
    label = new QLabel();
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    label->setAlignment(Qt::AlignCenter);

    startBtn = new QPushButton("Start/Restart", this);
    pauseBtn = new QPushButton("Pause", this);
    quitBtn = new QPushButton("Quitter", this);
    switchBtn= new QPushButton("Switch", this);
         startBtn->setFocusPolicy(Qt::NoFocus);
        quitBtn->setFocusPolicy(Qt::NoFocus);
        pauseBtn->setFocusPolicy(Qt::NoFocus);
        switchBtn->setFocusPolicy(Qt::NoFocus);

    boardT = new Board;
    boardV = new Board2;
    surfaceLcd = new QLCDNumber();

    //pauseBtn->setVisible(false);
    QGridLayout *layout = new QGridLayout();
    QGridLayout *ouest_layout = new QGridLayout();
    QGridLayout *est_layout = new QGridLayout();
    ouest_layout->addWidget(startBtn, 0, 0);
    ouest_layout->addWidget(pauseBtn, 1, 0);
    ouest_layout->addWidget(quitBtn, 2, 0);
    ouest_layout->addWidget(switchBtn, 3, 0);
    ouest_layout->addWidget(surfaceLcd, 4, 0);
    est_layout->addWidget(boardT, 0, 0);
    est_layout->addWidget(boardV, 0, 0);
    layout->addLayout(ouest_layout, 0, 0);
    layout->addLayout(est_layout, 0, 1);
    setLayout(layout);
    connect(switchBtn, SIGNAL(clicked()), this, SLOT(switchB()));
    connect(startBtn, SIGNAL(clicked()), boardT, SLOT(start()));
    connect(startBtn, SIGNAL(clicked()), this, SLOT(switchStartRestartBtn()));
    connect(quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pauseBtn, SIGNAL(clicked()), boardT, SLOT(pause()));
    connect(pauseBtn, SIGNAL(clicked()), this, SLOT(switchPausePlayBtn()));
    connect(boardT, SIGNAL(scoreChanged(int)), surfaceLcd, SLOT(display(int)));

    setWindowTitle("Tetris");
    resize(600, 400);
}
void Window::switchB(){
     switchVisu=!switchVisu;
      if(switchVisu){

        boardT->timer.stop();
        boardT->clear();
        boardV->timer.start(1000, this);
        boardV->start();
        pauseBtn->setVisible(false);
        startBtn->setVisible(false);
        surfaceLcd->setVisible(false);




      }
        else{
          boardV->timer.stop();
          boardV->vBoard.clear();
          boardT->start();
          pauseBtn->setVisible(true);
          startBtn->setVisible(true);
           surfaceLcd->setVisible(true);
              }



}

void Window::switchStartRestartBtn() {
    if (boardT->isStarted())
        return;

    startBtn->setText(tr("Restart"));
    pauseBtn->setVisible(true);
    update();
}

void Window::switchPausePlayBtn() {
    if (boardT->isPaused()) {
        pauseBtn->setText("Play");
    } else {
        pauseBtn->setText("Pause");
    }
    update();
}



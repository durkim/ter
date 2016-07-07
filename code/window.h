/**
 * \file window.h
 * \brief représente l'interface graphique de l'application
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 *
 *
 */
#ifndef POLYOMINOES_WINDOW_H
#define POLYOMINOES_WINDOW_H

#include <QWidget>
#include <QGraphicsWidget>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include "Board.h"
#include "Board2.h"

/**
 * @brief The Window class
 * contient tous les widgets de l'application
 */
class Window : public QWidget {
Q_OBJECT
public slots:
    /**
     * @brief switchStartRestartBtn
     * permet de lier le bouton start de l'apply et la fonction board::start().
     */
    void switchStartRestartBtn();
    /**
     * @brief switchPausePlayBtn
     * permet de lier le bouton start de l'apply et la fonction board::pause().
     */
    void switchPausePlayBtn();
    void switchB();
public:

    /**
     * @brief board
     * le widget ou l'on dessine
     */
    Board *boardT;
    /**
     * @brief board2
     *
     */
    Board2 *boardV;
    /**
     * @brief label
     * nom de widget
     */
    QLabel *label;
    /**
     * @brief startBtn
     * bouton start
     */
    QPushButton *startBtn;
    /**
     * @brief pauseBtn
     * bouton pause
     */
    QPushButton *pauseBtn;
    /**
     * @brief quitBtn
     * bouton quit
     */
    QPushButton *quitBtn;
    /**
     * @brief surfaceLcd
     * affichage du score
     */
    QLCDNumber *surfaceLcd;
    /**
     * @brief switchBtn
     * switch pour passer en mode visualisation de polyominos
     */
    QPushButton *switchBtn;
     bool switchVisu=false;


public:/**
     * @brief Window
     * constructeur
     */
    Window();
};


#endif //POLYOMINOES_WINDOW_H

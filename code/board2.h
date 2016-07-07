/**
 * \file board2.h
 * \brief représente le polyomino que l'on doit construire
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 * Moteur du jeu
 *
 */
#ifndef BOARD2_H
#define BOARD2_H
#include <QFrame>
#include <QBasicTimer>
#include <QTimerEvent>
#include "UnitCell.h"
#include "Segment.h"
#include "matrix.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QFile>
#include <QTextStream>
using namespace std;/**
 * @brief The Board2 class
 * dessine un polyomino à partir d'une liste de segments
 */
class Board2 : public QFrame {
Q_OBJECT


public:/**
     * @brief Board2
     * constructeur
     * @param parent
     */
    Board2(QWidget *parent = 0);
    /**
     * @brief boardHeight
     * hauteur
     */
    int boardHeight=25;
    /**
     * @brief boardWidth
     * largeur
     */
    int boardWidth=25;
    /**
     * @brief timer
     * timer
     */

    QBasicTimer timer;
    /**
     * @brief vBoard
     * liste des board chargé
     */
    vector<matrix*> vBoard;
    int squareWidth() { return contentsRect().width() / boardWidth; }
    int squareHeight() { return contentsRect().height() / boardHeight; }
    /**
     * @brief timerEvent
     * achange de polyomino toutes les 1 secondes
     * @param event
     */
    void timerEvent(QTimerEvent *event);
    /**
     * @brief paintEvent
     * dessine le polyiomino
     * @param event
     */
    void paintEvent(QPaintEvent *event);
    /**
     * @brief lecture
     * lie le fichier
     */
    void lecture();
    /**
     * @brief parser
     * parse une string d'une liste de polyomino et le convertie en matrice
     * @param s
     * @return
     */
    matrix* parser(string s);
    /**
     * @brief time
     * temps
     */
    int time=0;
    public slots:
    void start();
    /*matrix * parseFichier(int n, char * buffer);*/

};

#endif // BOARD2_H

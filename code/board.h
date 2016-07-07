/**
 * \file board.h
 * \brief gestion de la partie.
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 * Moteur du jeu
 *
 */
#ifndef POLYOMINOES_BOARD_H
#define POLYOMINOES_BOARD_H


#include <QFrame>
#include <QBasicTimer>
#include <QTimerEvent>
#include "UnitCell.h"
#include "Segment.h"
#include "matrix.h"
using namespace std;

/**
 * \enum Mouvement
 * \brief Move
 *
 * Definit les mouvement de déplacement des polyominos
 */
enum {
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
};

/*! \class Board
* \brief classe representant le lecteur
*
* La classe gere l'affichage et le deroulement de la partie
*/
class Board : public QFrame {
Q_OBJECT

signals:
    /**
     * @brief scoreChanged
     * envoie le score au widget d'affichage du score
     * @param score
     */
    void scoreChanged(int score);

public slots:
    /**
     * @brief start
     * lance la partie
     */
    void start();
    /**
     * @brief pause
     * met en pause la partie
     */
    void pause();


public:/**
     * @brief boardHeight
     * taille en hauteur du board
     */
    int boardHeight=25;
    /**
     * @brief boardWidth
     * taille en largeur du board
     */
    int boardWidth=25;
    /**
     * @brief score
     * score de la partie
     */
    int score=0;
    /**
     * @brief fini
     * definit si une parite est fini
     */
    bool fini=false;
    /**
     * @brief timer
     * timer du widget
     */
    /**
     * @brief acc
     * compte le nombre de piece posé
     */
    int acc=0;
    QBasicTimer timer;
    /**
     * @brief board
     * représente les polyominos sous forme d'une matrice de 0 et de 1
     */
    matrix* board;
    /**
     * @brief curSegment
     * le segment qui est entrain d'être poser
     */
    Segment *curSegment = NULL;
    /**
     * @brief segments
     * liste des segments deja posé
     */
    std::vector<Segment> segments;
    /**
     * @brief paused
     * definit si la partie est en pause
     */
    bool paused = false;
    /**
     * @brief started
     *definit si la partie est lancé
     */
    bool started = false;
    /**
     * @brief segmentDropped
     * definit si le segment courant a été posé
     */
    bool segmentDropped = false;
    /**
     * @brief keyPressEvent
     * gére le mouvement avec les touches du clavier
     * @param event
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * @brief squareWidth
     * definit la taille d'une case d'un polyominos
     * @return
     */
    int squareWidth() { return contentsRect().width() / boardWidth; }
    /**
     * @brief squareHeight
     * definit la taille d'une case d'un polyominos
     * @return
     */
    int squareHeight() { return contentsRect().height() / boardHeight; }
public:
    /**
     * @brief Board
     * constructeur
     * @param parent
     */
    Board(QWidget *parent = 0);
    /**
     * @brief timerEvent
     * appelle les fonctions motrices du jeu toutes les 1 secondes
     * @param event
     */
    void timerEvent(QTimerEvent *event);
    /**
     * @brief tryMoveR
     * verifie qu'un segment à le doit de se déplacer vert la droite
     * @param segment
     * @return
     */
    bool tryMoveR(Segment *segment);
    /**
     * @brief tryMoveL
     * verifie qu'un segment à le doit de se déplacer vert la gauche
     * @param segment
     * @return
     */
    bool tryMoveL(Segment *segment);
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    /**
     * @brief paintEvent
     * permet de dessiner les polyominos
     * @param event
     */
    void paintEvent(QPaintEvent *event);

    /**
     * @brief tryMove
     * verifie qu'un segment à le doit de se déplacer vers le bas
     * @param segment
     * @return
     */
    bool tryMove(Segment *segment);

    /**
     * @brief move
     * effectie le mouvement
     * @param movement
     */
    void move(int movement);
    /**
     * @brief colGen
     * génère un polyomino en forme de barre de taille aléatoire
     * @param f sa position verticale ou horizontale
     */
    void colGen(bool f);
    /**
     * @brief isPaused
     * renvoie true si le jeu est en pause
     * @return
     */
    bool isPaused() const {
        return paused;
    }
    /**
     * @brief isStarted
     * renvoie true si le jeu à commencer
     * @return
     */
    bool isStarted() const {
        return started;
    }
    /**
     * @brief polyo
     * verifie si c'est un polyomino
     * @return
     */
    bool polyo();
    /**
     * @brief updateBoard
     * met a jour le board et affichage d'informations
     * @param segment
     */
    void updateBoard(Segment *segment);
    /**
     * @brief prefixClosed
     * verifie si le poyomino est bien prefixe close
     * @return
     */
    bool prefixClosed();
    /**
     * @brief tryRotate
     * verifie que le segment peut faire une rorarion
     * @param segment
     * @return
     */
    bool tryRotate(Segment *segment);
    /**
     * @brief clear
     * nettoie le board
     */
    void clear();



};


#endif //POLYOMINOES_BOARD_H

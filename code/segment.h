/**
 * \file segment.h
 * \brief représente une partie du polyomino
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 *
 *
 */
#ifndef POLYOMINOES_SEGMENT_H
#define POLYOMINOES_SEGMENT_H

#include "UnitCell.h"

using namespace std;
/**
 * @brief The Segment class
 * Représente un liste d'unicell
 */
class Segment {


public:/**
     * @brief cells
     * toutes les UnitCell qui constitue le segment
     */
    vector<UnitCell> cells;
    /**
     * @brief Segment
     * constructeur
     * @param x
     * coordonée de départ du segment
     * @param y
     * coordonée de départ du segment
     * @param area
     * sa taille
     * @param f
     * sa position true si horizontale
     */
    Segment(int x, int y, int area,bool f);
    /**
     * @brief verticale
     * true si horizontale
     */
    bool verticale;
    /**
     * @brief draw
     * dessine une par une les unitcells
     * @param painter
     * @param x
     * @param y
     * @param sh
     * @param sw
     */
    void draw(QPainter &painter, int x, int y,int sh ,int sw);

    /**
     * @brief rotate
     * permet la rotation d'un segment à 90dégrès
     */
    void rotate();

    /**
     * @brief getUnitCell
     * renvoie l'unitcell à l'index indiqué
     * @param index
     * @return
     */
    UnitCell *getUnitCell(int index) {
        return &cells[index];
    }
    /**
     * @brief getCells
     * renvoie toutes les unitcells
     * @return
     */
    vector<UnitCell> *getCells() {
        return &cells;
    }
    /**
     * @brief getSize
     * renvoie la taille
     * @return
     */
    int getSize() const {
        return cells.size();
    }
    /**
     * @brief color
     * couleur du segment
     */
    QColor color;
    /**
     * @brief isDown
     * verifie sur le segment est placé
     * @return
     */
    bool isDown();
    /**
     * @brief neighbor
     * @param other
     * @return
     */
    bool neighbor(Segment* other);
    /**
     * @brief reset
     * verifie si 2 segments sont voisin
     * @param x
     */
    /**
     * @brief reset
     * remet un segment à ses coordonées d'origine
     * @param x
     */
    void reset(int x);

};


#endif //POLYOMINOES_SEGMENT_H

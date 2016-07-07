/**
 * \file UnitCell.h
 * \brief représente une cellule de polyomino
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 */
#ifndef POLYOMINOES_UNITCELL_H
#define POLYOMINOES_UNITCELL_H


#include <QPainter>
#include <iostream>
/**
 * @brief The UnitCell class
 * contient la taille ,la couleur,et les coordonées d'une celluled'un polyomino
 */
class UnitCell {
protected:
    /**
     * @brief h
     * sa hauteur
     */
    static int h;
    /**
     * @brief w
     * sa largeur
     */
    static int w;
public:
    /**
     * @brief x
     * coordonés abscisse
     */
    int x = 0;
    /**
     * @brief y
     * coordonés ordonné
     */
    int y = 0;
    /**
     * @brief color
     * couleur
     */
    QColor color;
    /**
     * @brief setSize
     * change la hauteur et la largeur
     * @param h
     * @param w
     */
    static void setSize(int h, int w);
    /**
     * @brief getHeight
     * accesseur de la hauteur
     * @return
     */
    static int getHeight();
    /**
     * @brief getWidth
     * accesseur de la largeur
     * @return
     */
    static int getWidth();

    /**
     * @brief UnitCell
     * constructeur
     * @param x
     * @param y
     * @param color
     */
    UnitCell(int x,int y, QColor color);
    /**
     * @brief draw
     * dessine une cellule de polyomino
     * @param painter
     * @param x
     * @param y
     * @param sh
     * @param sw
     */
    void draw(QPainter &painter ,int x, int y,int sh ,int sw);
};


#endif //POLYOMINOES_UNITCELL_H

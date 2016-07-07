/**
 * \file UnitCell.cpp
 * \brief représente une cellule de polyomino
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 */
#include <iostream>
#include "UnitCell.h"

int UnitCell::h = 0;
int UnitCell::w = 0;

void UnitCell::setSize(int h_, int w_) {
    h = h_;
    w = w_;
}

int UnitCell::getHeight() {
    return h;
}

int UnitCell::getWidth() {
    return w;
}




UnitCell::UnitCell(int x,int y, QColor color) {
    this->x = x;
    this->y = y;
    this->color = color;
}


void UnitCell::draw(QPainter &painter, int r, int t,int sh ,int sw)
{
    int py=r + y *sw;
    int px=t + x * sh;
    painter.fillRect(px + 1, py + 1, sw - 2, sh - 2,
                     color);

    painter.setPen(color.light());
    painter.drawLine(px, py + sh - 1, px, py);
    painter.drawLine(px, py, px + sw - 1, py);

    painter.setPen(color.dark());
    painter.drawLine(px + 1, py + sh - 1,
                     px + sw - 1, py + sh - 1);
    painter.drawLine(px + sw - 1, py + sh - 1,
                     px+ sw - 1, py + 1);


}


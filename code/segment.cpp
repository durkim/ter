/**
 * \file segment.cpp
 * \brief représente une partie du polyomino
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 *
 *
 */
#include <iostream>
#include <time.h>
#include "Segment.h"

Segment::Segment(int x, int y, int area,bool f) {
     int cellX = x;
     verticale=f;
    QRgb colorTable[7] = {
            0xCC6666, 0x66CC66, 0x6666CC,
            0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00

    };
    srand(time(NULL));
    color = colorTable[rand() % 7];

    for (int i = 0; i < area; i++) {

        cells.push_back(UnitCell(cellX,i, color));

    }

}

void Segment::draw(QPainter &painter,int x,int y,int sh ,int sw) {
    for (int j = 0; j < cells.size(); j++) {
       // cout << getUnitCell(j)->x << endl;
       // cout << getUnitCell(j)->y << endl;
        getUnitCell(j)->draw(painter,x,y,sh,sw);
    }
}

void Segment::rotate() {
    if(cells.size()==1){
        return;
    }
    else{
        if(cells[0].x==cells[1].x){
            for (int i = 1; i < cells.size(); i++) {
                cells[i].x=cells[0].x+i;
                cells[i].y=cells[0].y;

            }
            verticale=true;

        }
        else{
            for (int i = 0; i < cells.size(); i++) {
                cells[i].x=cells[0].x;
                cells[i].y=cells[0].y+i;

            }
            verticale=false;

    }
}}


bool Segment::isDown(){
    for (int i = 0; i < cells.size(); i++) {
        if(getUnitCell(i)->y ==25){
            return true;
        }
    }
    return false;

}
 bool Segment::neighbor(Segment* other){
     for (int i = 0; i < cells.size(); i++) {
         for (int j = 0; j < other->cells.size(); j++) {
             if(cells[i].x == other->cells[j].x && (cells[i].y == other->cells[j].y+1 ||cells[i].y == other->cells[j].y-1) ){
                     return true;
         }
             if(cells[i].y == other->cells[j].y && (cells[i].x == other->cells[j].x+1 ||cells[i].x == other->cells[j].x-1) ){
                     return true;
         }
     }
 }
     return false;}

 void Segment::reset(int x){
     for (int i = 0; i < cells.size(); i++) {
         cells[i]=UnitCell(x,i, color);
     }

 }

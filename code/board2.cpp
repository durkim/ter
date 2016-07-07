/**
 * \file board2.cpp
 * \brief représente le polyomino que l'on doit construire
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 * Moteur du jeu
 *
 */
#include "board2.h"

Board2::Board2(QWidget *parent) : QFrame(parent) {


    setFocusPolicy(Qt::StrongFocus);
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    UnitCell::setSize(contentsRect().height() / boardHeight, contentsRect().width() / boardWidth);
}

void  Board2::paintEvent(QPaintEvent *event){
     QFrame::paintEvent(event);
     QPainter painter(this);
     QRect rect = contentsRect();
     int boardTop = rect.bottom() -  boardHeight * squareHeight();

     if (vBoard.size() >= 1 && vBoard.size()>time) {
             vBoard.at(time)->draw(painter,rect.left(),boardTop,squareHeight(),squareWidth());


         }


 }


 matrix* Board2::parser(string s){
     bool signe=false;
     bool offset=true;
     int off=0;
     matrix *m=new matrix(boardHeight,boardWidth);
     int x,y;
     x=10;
     y=10;

     for(int k=0;k<s.size();k++)
     {

              int d=s.at(k);
         if(d==45){
             signe=true;
         }
         if(offset){
             if(d>=48 && d<=57 ){
                 off=atoi(&s.at(k));
                 offset=false;
                 if(signe){
                     off=off*(-1);
                     signe=false;
                 }


         }}
         else{
                   if(d>=48 && d<=57 ){

               y=y+off;
               int i=atoi(&s.at(k));
             for(int j=0;j<i;j++){

                 m->set(x,y+j);
             }
               x++;
               offset=true;

         }}}
     return m;}




  void Board2::lecture(){


            QString texte;
            QFile fichier("C:\\Users\\fagard\\Documents\\ter4\\polyo.txt");


            if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream flux(&fichier);
                while(!flux.atEnd())
                {
                    QString temp = flux.readLine();
                    texte += temp;
                    cout<<temp.toStdString()<<endl;
                    vBoard.push_back(parser(temp.toStdString()));
                }
                fichier.close();
  }}



    void Board2::timerEvent(QTimerEvent *event){

        if (event->timerId() == timer.timerId()) {

              update();
            time++;
                }
             else {
                QFrame::timerEvent(event);
            }
        }

    void Board2::start() {
        vBoard.clear();
           timer.start(500, this);

           lecture();
           time=0;

    }

    /*
   matrix * Board2::parseFichier(int n, char * buffer) {
       int * lignes =0;
      int i=0, k=0;
      // int numPol=0;
      int tmp;
      bool inPol = false;
      bool inColumn = false;
      bool inSegment = false;
      bool isOffset = false;
      bool isFirstSegment = false;
      int offset;
      int size;
      int x = n;
      int y = n;
      while(buffer[i] != 0) {
        if(buffer[i] == '\n') {
          (*lignes)++;
        }
        i++;
      }
     matrix * m =new matrix(boardHeight,boardWidth);
      i = 0;
      while(buffer[i] != 0) {
        if(buffer[i] == '{') {
          if(!inPol) {
            inPol = true;
          } else if(!inColumn) {
            inColumn = true;
            isFirstSegment = true;
          } else if(!inSegment) {
            inSegment = true;
            isOffset = true;
          }
        } else {
          if(inPol && inColumn && inSegment) {
            if(buffer[i] != '}' && buffer[i] != ',') {
              tmp[k++] = buffer[i];
            } else {
              tmp[k] = 0;
              k = 0;
              if(isOffset) {
                offset = atoi(tmp);
                if(isFirstSegment) {
                  y += offset;
                  offset = 0;
                  isFirstSegment = false;
                }
                isOffset = false;
              } else {
                size = atoi(tmp);
                for (int j = 0; j < size; i++) {
                  m->set(x, y+j+offset);
                }
              }
            }
          }
          else {
            if(buffer[i] != '}') {
              if(inSegment) {
                inSegment = false;
              } else if(inColumn) {
                inColumn = false;
                x++;
              } else if(inPol) {
                inPol = false;
                // numPol++;
              }
            }
          }
        }
        i++;
      }
      return m;
    }*/


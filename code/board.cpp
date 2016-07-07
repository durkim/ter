/**
 * \file board.cpp
 * \brief gestion de la partie.
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 * Moteur du jeu
 *
 */
#include <iostream>
#include <time.h>
#include "Board.h"
#include <QKeyEvent>
#include <fstream>


Board::Board(QWidget *parent) : QFrame(parent) {

    //QWidget::setContentsMargins ( 0, 0, -200, -360 );
    setFocusPolicy(Qt::StrongFocus);
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    UnitCell::setSize(contentsRect().height() / boardHeight, contentsRect().width() / boardWidth);
    board=new matrix(boardHeight,boardWidth);}

QSize Board::sizeHint() const
{
    return QSize(boardWidth * 15 + frameWidth() * 2,
                 boardHeight * 15 + frameWidth() * 2);
}

QSize Board::minimumSizeHint() const
{
    return QSize(boardWidth * 5 + frameWidth() * 2,
                 boardHeight * 5 + frameWidth() * 2);
}
void Board::start() {
     if (paused)
        return;

    started = true;
    score=0;
    emit scoreChanged(score);
    timer.start(1000, this);
    clear();
    colGen(true);
    fini=false;
}

void Board::pause() {
    if (!started)
        return;

    if (!paused) {
        paused = true;
        timer.stop();
    } else {
        paused = false;
        timer.start(1000, this);
    }
}

void Board::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timer.timerId()) {
        if (segmentDropped) {
            segmentDropped = false;
            colGen(false);
        } else {
            move(MOVE_DOWN);
        }
    } else {
        QFrame::timerEvent(event);
    }
}

void Board::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);

    QPainter painter(this);


        QRect rect = contentsRect();
    int boardTop = rect.bottom() -  boardHeight * squareHeight();

    if (curSegment != nullptr) {
        curSegment->draw(painter,rect.left(),boardTop,squareHeight(),squareWidth());
          if(curSegment->isDown()){
              segments.push_back(*curSegment);
              colGen(false);

          }
    }

    for (int i = 0; i < segments.size(); ++i) {
        segments[i].draw(painter,rect.left(),boardTop,squareHeight(),squareWidth());
    }

}


bool Board::tryMove(Segment *segment) {
        if(segment->getUnitCell(segment->getSize()-1)->y==boardHeight){
            return false;
        }
        if(!segment->verticale){
           return!(board->occuped(segment->getUnitCell(segment->getSize()-1)->x,segment->getUnitCell(segment->getSize()-1)->y));
        }
        else{
            for(int k = 0; k < segment->getSize();k++){
                if(board->occuped(segment->getUnitCell(k)->x,segment->getUnitCell(k)->y)){
                    return false;
                }}
        }
    return true;


}

void Board::move(int movement) {
    if (curSegment == nullptr)
        return;
    Segment *tmp = new Segment(*curSegment);
    for (int i = 0; i < tmp->getSize(); ++i) {
        switch (movement) {
            case MOVE_DOWN:
                tmp->getUnitCell(i)->y++;
                break;
            case MOVE_LEFT:
                tmp->getUnitCell(i)->x--;
                break;
            case MOVE_RIGHT:
                tmp->getUnitCell(i)->x++;
                break;
        }
    }
    if (tryMove(tmp)) {
        delete (curSegment);
        curSegment = tmp;
        update();
    } else {
        delete tmp;
        if(prefixClosed()){
            segments.push_back(*curSegment);
            colGen(false);
            acc++;
        }
        else{
            curSegment->reset(boardWidth/2);
        }
    }
}
void Board::updateBoard(Segment* tmp1){
        for (int k = 0; k < tmp1->getSize();k++) {
            board->set(tmp1->getUnitCell(k)->x,tmp1->getUnitCell(k)->y);

            board->matrixToList();
           cout<<endl;
            board->printlist();
             cout<<endl;

}}

void Board::colGen(bool f) {
    int mod=acc+1;
    if(mod>10)
        mod=9;
     board->afficher();
     cout<<endl;
    srand(time(NULL));
    Segment *t = new Segment(boardWidth / 2, 0, (rand() % mod) + 1,f);
    if(board->occuped(boardWidth / 2  ,t->getUnitCell(t->getSize()-1)->y)){
        fini=true;
        timer.stop();



}
    else{
        curSegment=t;
    }

}

void Board::keyPressEvent(QKeyEvent *event)
{
    //if (!isStarted || isPaused || curPiece.shape() == NoShape) {
    if(curSegment == nullptr){
        QFrame::keyPressEvent(event);
        return;
    }
    Segment *tmp = new Segment(*curSegment);
    switch (event->key()) {
    case Qt::Key_Left:
        if(tryMoveL(curSegment)){
            move(MOVE_LEFT);
        }
        break;
    case Qt::Key_Right:
        if(tryMoveR(curSegment)){
             move(MOVE_RIGHT);
        }

        break;
    case Qt::Key_Down:
        if(tryMove(curSegment)){
        move(MOVE_DOWN);
        break;
        }
   case Qt::Key_Up:
        if(tryRotate(tmp)){
        curSegment->rotate();
        delete(tmp);
        break;}

        QFrame::keyPressEvent(event);
    }
}

bool Board::tryMoveL(Segment *segment){
        if(segment->getUnitCell(0)->x==0){
           boardWidth++;
           int re=(width() + width()/boardWidth)/boardWidth;
           setFixedSize(width() +re,378);
           board->resizeGauche();
           for (int j = 0; j < segments.size(); j++) {
               for(int k = 0; k < segments[j].getSize();k++){
                   segments.at(j).cells[k].x=segments.at(j).cells[k].x+1;
               }
           }
            return false;
        }
        else{
            if(segment->verticale){
                return !board->occuped(segment->getUnitCell(0)->x-1,segment->getUnitCell(0)->y);
                }
            else{
                for(int k = 0; k < segment->getSize();k++){
                    if(board->occuped(segment->getUnitCell(k)->x-1,segment->getUnitCell(k)->y)){
                        return false;
                    }
             }}
    }
    return true;


}
bool Board::tryRotate(Segment *segment){
    int diff=0;
    segment->rotate();
       if(segment->getUnitCell(segment->getSize()-1)->y >= boardHeight){
            return false;}
       if(segment->getUnitCell(segment->getSize()-1)->x >= boardWidth){
            diff=segment->getUnitCell(segment->getSize()-1)->x-boardWidth;
            for(int k = 0; k < diff+1;k++){
            boardWidth++;
            int re=(width() + width()/boardWidth)/boardWidth;
            setFixedSize(width() +re,378);
            board->resizeDroite();}
       }
       for(int k = 0; k < segment->getSize();k++){
           if(board->occuped(segment->getUnitCell(k)->x,segment->getUnitCell(k)->y)){
               return false;
           }}


        return true;}

bool Board::tryMoveR(Segment *segment){
        if(segment->getUnitCell(segment->getSize()-1)->x==boardWidth-1){
           boardWidth++;
           int re=(width() + width()/boardWidth)/boardWidth;
           setFixedSize(width() +re,378);
           board->resizeDroite();

            return true;
        }
        else{
            if(segment->verticale){
                return !board->occuped(segment->getUnitCell(segment->getSize()-1)->x+1,segment->getUnitCell(segment->getSize()-1)->y);
                }
            else{
                for(int k = 0; k < segment->getSize();k++){
                    if(board->occuped(segment->getUnitCell(k)->x+1,segment->getUnitCell(k)->y)){
                        return false;
                    }

            }}

    }
    return true;
}


bool Board::polyo(){
    if(segments.size()==0){
        return true;
    }
    else{
        for (int j = 0; j < segments.size(); j++) {
            if(curSegment->neighbor(&segments[j])){
                return true;
            }

    }
        return false;
}
}

bool Board::prefixClosed(){
    bool colone1=true;
    if(polyo()){
        matrix* copyBoard=new matrix(board);

        updateBoard(curSegment);
        for (int j = 0; j < board->sizeCol; j++) {
           if(!board->vecNull(board->vec.at(j))){
              if(colone1){
                  colone1=false;
                  vector<int> myvector;
                  myvector=board->vecteurToList(board->vec.at(j));
                  if(myvector.size()>1){

                      board=copyBoard;
                      score=score-10;
                      emit scoreChanged(score);
                      return false;
                  }

              }
              else{
                   vector<int> copy=board->vec.at(j);


                  for(int k=0;k<board->vec.at(j).size();k++){

                      if(board->vec.at(j).at(k)==board->vec.at(j-1).at(k) && board->vec.at(j).at(k)==1 ){
                          board->propagation(&board->vec.at(j),k);
                      }
                   }

                   for(int k=0;k<board->vec.at(j).size();k++){

                       if(board->vec.at(j).at(k)==1){
                           board=copyBoard;
                           score=score-10;
                           emit scoreChanged(score);
                           return false;
                       }
                   }
                   board->vec.at(j)=copy;



              }}
    }
        score++;
        emit scoreChanged(score);

    return true;
    }
    else{
        score=score-10;
        emit scoreChanged(score);
         return false;
    }




}

void Board::clear(){
    boardWidth=25;
    boardHeight=25;
    segments.clear();
    acc=0;
    setFixedSize(377,377);
    board=new matrix(25,25);
    delete(curSegment);
}








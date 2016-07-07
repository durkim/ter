/**
 * \file matrix.cpp
 * \brief gestion des déplacement
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 *controle les déplacements et transformations
 *
 */
#include "matrix.h"
#include <iostream>

matrix::matrix(int i,int j)
{
  sizeRow=i;
  sizeCol=j;
  for(int i=0;i<sizeRow;i++){
       vector<int> myvector;
      for(int j=0;j<sizeCol;j++){
          myvector.push_back(0);
       }
      vec.push_back(myvector);}


}
matrix::matrix(matrix *obj){
    sizeCol=obj->sizeCol;
    sizeRow=obj->sizeRow;
    vec=obj->vec;
    l=obj->l;
}
 void matrix::set(int x,int y){

    vec.at(x).at(y)=1;
 }

 bool matrix::occuped(int x,int y){

    return vec.at(x).at(y)==1;

 }

 void matrix::afficher(){
     for(int i=0;i<sizeCol;i++){
         for(int j=0;j<sizeRow;j++){
        cout << vec.at(j).at(i);
         }
         cout<< " " << endl;
     }

   }
void  matrix::resizeDroite(){
     vector<int> myvector;
    for(int j=0;j<sizeCol;j++){
        myvector.push_back(0);
     }
    vec.push_back(myvector);
     sizeRow++;}

void  matrix::resizeGauche(){
     vector<int> myvector;
    for(int j=0;j<sizeCol;j++){
        myvector.push_back(0);
     }
    vec.insert(vec.begin(),myvector);
     sizeRow++;}

void matrix::matrixToList(){
    l.clear();
    bool start=true;
    vector<int> myvector;
    for(int i=0;i<sizeCol;i++){
        if(!vecNull(vec.at(i))){
            //cout<<i<<endl;
            if(start){
                start=false;
            myvector=vecteurToList(vec.at(i));
           // cout<< myvector.size()<<endl;
            l.push_back(myvector);
            for(int j=0;j<myvector.size();j++){
               // cout<<myvector[j]<<endl;
            }
          /*  cout<<"taille m"<<endl;
             cout<< myvector.size();
             cout<<"taille m"<<endl;
            //cout<< myvector.size();*/
            }
            else{
            int offset=calculOffset(vec.at(i-1),vec.at(i));
            myvector = vecteurToList(vec.at(i));
            myvector.insert(myvector.begin(),offset);
             l.push_back(myvector);

            }




            }

        }
       l.at(0).insert(l.at(0).begin(),0);
    }


bool matrix::vecNull(vector<int> v){
     for(int i=0;i<v.size();i++){
         if(v.at(i)!=0){
             return false;
         }

     }
     return true;

}

vector<int> matrix::vecteurToList(vector<int> v){
    bool debut=true;
    int acc=0;
    vector<int> li;
     for(int i=0;i<v.size();i++){

         if(i+1<v.size()){
         if(debut){
             if(v.at(i)==1){
                 debut=false;
                 if(v.at(i)==v.at(i+1)){
                     acc++;

                 }
                 else{
                     li.push_back(1);
                 }


             }
         }
         else{

             if(v.at(i)==v.at(i+1)){
                 acc++;

             }
             else{
                 //cout<<acc + 1<<endl;
                 li.push_back(acc+1);
                 acc=0;
             }
         }

}
}

     li.push_back(acc+1);
     for(int j=0;j<li.size();j++){

     }


     return li;

}

int matrix::calculOffset(vector<int> v1,vector<int> v2){
    int t1,t2;
     for(int i=0;i<v1.size();i++){
          if(v1.at(i)==1){
              t1=i;
            //  cout<<t1<<endl;
              break;
          }
     }
     for(int i=0;i<v2.size();i++){
          if(v2.at(i)==1){
              t2=i;
               //cout<<t2<<endl;
               break;
          }
     }
     return t2-t1;



}
void  matrix::printlist(){
   // cout<<l.size();
    cout<< "(";
     for(int i=0;i<l.size();i++){
         if(i==0){
                cout<< "{";
         }
         else{
             cout<< ",";
               cout<< "{";
         }
         for(int j=0;j<l.at(i).size();j++){

             if(j==0){
                 cout<< "{";
                 cout<< l.at(i).at(j);

             }
             else{
                 if(j%2==0 && j!=0){
                      cout<< "{";
                       cout<< l.at(i).at(j);
                 }
                 else{
                     cout<< ",";
                    cout<< l.at(i).at(j);
                    cout<< "}";

                 }

            }

         }
         cout<< "}";
     }
   cout<< "}";
     l.clear();

}
void matrix::propagation(vector<int> *v ,int i){


    for(int j=i;j+1<v->size();j++){





        if(!v->at(j)==v->at(j+1)){
            v->at(j)=0;
           break;
        }
        else{
            if(j!=i){
             v->at(j)=0;
            }
             if(j+1==v->size()-1){
                v->at(j+1)=0;
             }
        }

    }
    for(int j=i;j>0;j--){

        if(!v->at(j)==v->at(j-1)){
            v->at(j)=0;
           break;
        }
        else{
             v->at(j)=0;
             if(j-1==0){
                v->at(j-1)=0;
             }
        }

    }

}

void matrix::draw(QPainter &painter, int r, int t,int sh ,int sw){
    for(int i=0;i<sizeRow;i++){
        for(int j=0;j<sizeCol;j++){
            if(vec.at(j).at(i)==1){
                QColor color=0xCC6666;
                int py=r + i * sh;
                int px=t + j * sw;
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

            }
        }

}




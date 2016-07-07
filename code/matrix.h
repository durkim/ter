/**
 * \file matrix.h
 * \brief gestion des déplacement
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 *controle les déplacements et transformations
 *
 */
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <list>
#include <QPainter>
#include <string>
using namespace std;

/**
 * @brief The matrix class
 * une matrice constituer de vecteur de vecteur
 */
class matrix
{
public:/**
     * @brief matrix
     * contrucreur matrice 2 d
     * @param i ligne
     * @param j colone
     */
    matrix(int i,int j);
    /**
     * @brief matrix
     * constructeur par copie
     * @param obj
     */
    matrix(matrix *obj);
    /**
     * @brief sizeRow
     * taille ligne
     */
    int sizeRow;/**
     * @brief sizeCol
     * taille colone
     */
    int sizeCol;
    /**
     * @brief vec
     * l'architecture de la matrice
     */
    vector<vector<int> > vec;
    /**
     * @brief l
     * représente le polyomino sous forme de liste
     */
    vector<vector<int> > l;
    /**
     * @brief set
     * met un 1 à la case de la matrice{x][y]
     * @param x
     * @param y
     */
    void set(int x,int y);
    /**
     * @brief afficher
     * affiche la matrice
     */
    void afficher();
    /**
     * @brief resizeDroite
     * ajoute un vecteur remplie de 0 de taile sizeRow à droite
     */
    void resizeDroite();
    /**
     * @brief resizeGauche
     *  ajoute un vecteur remplie de 0 de taile sizeRow à gauche
     */
    void resizeGauche();
    /**
     * @brief occuped
     * verifie si l'emplacement de la matrice[x][y] est occupé
     * @param x
     * @param y
     * @return
     */
    bool occuped(int x,int y);
    /**
     * @brief matrixToList
     * convertie la matrice en afficga en liste de segment plein
     */
    void matrixToList();
    /**
     * @brief vecNull
     * verifie si le vecteur v est remplie de 0
     * @param v
     * @return
     */
    bool vecNull(vector<int> v);
    /**
     * @brief vecteurToList
     * convertie un vecteir en un liste qui représente les segments pleins
     * @param v
     * @return
     */
    vector<int> vecteurToList(vector<int> v);
    /**
     * @brief calculOffset
     * calcule la différence de déplacement a faire entre v1 et v2
     * @param v1
     * @param v2
     * @return
     */
    int calculOffset(vector<int> v1,vector<int> v2);
    /**
     * @brief printlist
     * affiche la liste
     */
    void printlist();
    /**
     * @brief propagation
     * élimine les 1 consécutif dans les 2 sens du vecteur à l'indice i
     * @param v
     * @param i
     */
    void propagation(vector<int> *v ,int i);
    /**
     * @brief draw
     * dessine le polyomino à partir de la matrice
     * @param painter
     * @param x
     * @param y
     * @param sh
     * @param sw
     */
    void draw(QPainter &painter, int x, int y,int sh ,int sw);

};


#endif // MATRIX_H

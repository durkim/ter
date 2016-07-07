/**
 * \file main.cpp
 * \brief la main classe
 * \author Fagard.C
 * \version 0.1
 * \date 14juin 2016
 *
 *
 *
 */
#include <iostream>
#include <QtGui>
#include <QApplication>
#include "Window.h"
using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}

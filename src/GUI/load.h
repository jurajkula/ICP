/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

#ifndef LOAD_H
#define LOAD_H

#include "mainwindow.h"
#include "save.h"

class Load
{
public:
    Load(QFile *file);

    MainWindow *mainwindow;
};

#endif // LOAD_H

/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

#ifndef LOAD_H
#define LOAD_H

#include "mainwindow.h"
#include "save.h"

class MainWindow;

struct LoadConnect {
    int source;
    int dest;
};

class Load
{
public:
    Load(QFile *file);

private:
    MainWindow *mainwindow;
    std::vector<LoadConnect> listConnection;
};

#endif // LOAD_H

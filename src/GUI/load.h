/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre načítavanie schém
*/

#ifndef LOAD_H
#define LOAD_H

#include "mainwindow.h"
#include "save.h"

class MainWindow;

/**
 * @brief The LoadConnect struct
 */
struct LoadConnect {
    /**
     * @brief source ID of source port
     */
    int source;

    /**
     * @brief dest ID of dest port
     */
    int dest;
};

/**
 * @brief The Load class
 */
class Load
{
public:
    /**
     * @brief Load Constructor of the class
     * @param file Pointer to file
     */
    Load(QFile *file);

private:
    /**
     * @brief mainwindow Pointer to mainwindow
     */
    MainWindow *mainwindow;

    /**
     * @brief listConnection Vector of connections - ID of both ports
     */
    std::vector<LoadConnect> listConnection;
};

#endif // LOAD_H

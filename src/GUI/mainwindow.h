/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre hlavné okno aplikácie
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMessageBox>
#include <QToolBar>
#include <QFileDialog>

#include "ui_mainwindow.h"
#include "GraphicsScene.h"
#include "../LOGIC/Scheme.hpp"
#include "graphicsview.h"
#include "load.h"

class Load;

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow Cosntructor of class MainWindow
     * @param name Name of the scheme
     * @param parent Parent window
     */
    explicit MainWindow(std::string name, QWidget *parent = 0);

    ~MainWindow();

    /**
     * @brief getUI Function which return pointer to UI
     * @return Return pointer UI
     */
    Ui::MainWindow *getUI();

    /**
     * @brief getScene Function which return pointer to graphics scene
     * @return Return pointer to scene
     */
    QGraphicsScene *getScene();

    /**
     * @brief getScheme Function which return pointer to logic scheme
     * @return Pointer to logic scheme
     */
    Scheme *getScheme();

    /**
     * @brief getPortNodeByPortUniqueID Function which return pointer to PortNode - Function find portNode by Port unique ID
     * @param id Port unique ID
     * @return Pointer to PortNode
     */
    PortNode *getPortNodeByPortUniqueID(int id);


private slots:

    /**
     * @brief on_actionQuit_2_triggered Quit program
     */
    void on_actionQuit_2_triggered();

    /**
     * @brief on_actionTutorial_triggered Help
     */
    void on_actionTutorial_triggered();

    /**
     * @brief on_actionSave_2_triggered Save scheme
     */
    void on_actionSave_2_triggered();

    /**
     * @brief on_actionLoad_2_triggered Load scheme
     */
    void on_actionLoad_2_triggered();

private:
    /**
     * @brief ui GUI window
     */
    Ui::MainWindow *ui;

    /**
     * @brief scene Scene of window
     */
    QGraphicsScene *scene;

    /**
     * @brief scheme Logic scheme
     */
    Scheme *scheme;
};

#endif // MAINWINDOW_H

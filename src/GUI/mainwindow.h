#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMessageBox>
#include <QToolBar>

#include "ui_mainwindow.h"
#include "GraphicsScene.h"
#include "../LOGIC/Scheme.hpp"



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
     * @brief getUI
     * @return
     */
    Ui::MainWindow *getUI();

private slots:

    /**
     * @brief on_actionQuit_2_triggered Quit program
     */
    void on_actionQuit_2_triggered();

    /**
     * @brief on_actionTutorial_triggered Help
     */
    void on_actionTutorial_triggered();


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

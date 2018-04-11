#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMessageBox>
#include <QDebug>
#include <QMessageBox>
#include <QDebug>
#include <QToolBar>

#include "ui_mainwindow.h"
#include "GraphicsScene.h"
#include "gBlock.h"
#include "../LOGIC/Scheme.hpp"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionQuit_2_triggered();

    void on_actionTutorial_triggered();

private:
    Ui::MainWindow *ui;
    //ideme si robit scenu
    QGraphicsScene *scene;
    //formovanie noveho okna

    Scheme *scheme;
};

#endif // MAINWINDOW_H

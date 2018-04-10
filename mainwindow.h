#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "form.h"
#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
// asi treba pouzivat widgets lebo gui nepozna
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>




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
    QGraphicsRectItem *rectangle;
    //formovanie noveho okna

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOWTOOLS_H
#define MAINWINDOWTOOLS_H

#include "ui_mainwindowtools.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <src/LOGIC/Scheme.hpp>

namespace Ui {
class mainWindowTools;
}

class mainWindowTools : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindowTools(Scheme *scheme, QGraphicsScene *scene, QWidget *parent = 0);
    ~mainWindowTools();

    QPushButton *getRun();
    QPushButton *getDebug();
    QPushButton *getNext();
    QPushButton *getStop();

protected slots:
    void RUN_clicked();
    void DEBUG_clicked();
    void NEXT_clicked();
    void STOP_clicked();

private:
    Ui::mainWindowTools *ui;

    QPushButton *run;
    QPushButton *debug;
    QPushButton *next;
    QPushButton *stop;
    Scheme *scheme;
    QGraphicsScene *scene;
    void restoreDefault();
    bool computation = false;
    bool debugging = false;
};

#endif // MAINWINDOWTOOLS_H

/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre nástroje programu - RUN, DEBUG, NEXT, STOP
*/

#ifndef MAINWINDOWTOOLS_H
#define MAINWINDOWTOOLS_H

#include "ui_mainwindowtools.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <src/LOGIC/Scheme.hpp>
#include <src/GUI/blockGraphics/rectangle.h>

namespace Ui {
class mainWindowTools;
}

/**
 * @brief The mainWindowTools class
 */
class mainWindowTools : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief mainWindowTools Constructor of the class
     * @param scheme Pointer to logic scheme
     * @param scene Pointer to graphics scene
     * @param parent Pointer to parent widget
     */
    explicit mainWindowTools(Scheme *scheme, QGraphicsScene *scene, QWidget *parent = 0);
    ~mainWindowTools();

    /**
     * @brief getRun Function which return button RUN
     * @return Button RUN
     */
    QPushButton *getRun();

    /**
     * @brief getDebug Function which return button DEBUG
     * @return Button DEBUG
     */
    QPushButton *getDebug();

    /**
     * @brief getNext Function which return button NEXT
     * @return Button NEXT
     */
    QPushButton *getNext();

    /**
     * @brief getStop Function which return button STOP
     * @return Button STOP
     */
    QPushButton *getStop();

protected:
    /**
     * @brief restoreDefault Function which return block to default value
     */
    void restoreDefault();

protected slots:
    /**
     * @brief RUN_clicked Function which grab signal clicked on button RUN
     */
    void RUN_clicked();

    /**
     * @brief DEBUG_clicked Function which grab signal clicked on button DEBUG
     */
    void DEBUG_clicked();

    /**
     * @brief NEXT_clicked Function which grab signal clicked on button NEXT
     */
    void NEXT_clicked();

    /**
     * @brief STOP_clicked Function which grab signal clicked on button STOP
     */
    void STOP_clicked();

private:
    /**
     * @brief ui Pointer to UI
     */
    Ui::mainWindowTools *ui;

    /**
     * @brief run Button run
     */
    QPushButton *run;

    /**
     * @brief debug Button debug
     */
    QPushButton *debug;

    /**
     * @brief next Button next
     */
    QPushButton *next;

    /**
     * @brief stop Button stop
     */
    QPushButton *stop;

    /**
     * @brief scheme Pointer to logic scheme
     */
    Scheme *scheme;

    /**
     * @brief scene Pointer to graphics scene
     */
    QGraphicsScene *scene;

    /**
     * @brief computation State if block was computed
     */
    bool computation = false;

    /**
     * @brief debugging State if debugging is running
     */
    bool debugging = false;
};

#endif // MAINWINDOWTOOLS_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "mainwindow.h"
#include "ui_dialog.h"

namespace Ui {
class Dialog;
}

/**
 * @brief The Dialog class
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Dialog Constructor of the class
     * @param parent Pointer to parent window
     */
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    /**
     * @brief getUI Support function, which returns UI
     * @return Return UI
     */
    Ui::Dialog *getUI();

    /**
     * @brief accept Rewrite function accept() - do nothing
     */
    virtual void accept();

private slots:

    /**
     * @brief on_buttonBox_accepted Function, which collects singla accepted
     */
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
};

#endif // DIALOG_H

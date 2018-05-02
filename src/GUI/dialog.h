/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre dialóg (názov schémy).Buď vytvorí hlavné okno progrmau alebo sa vráti späť do menu.
*/

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

    /**
     * @brief getMainWindow Function which return pointer to main window of app
     * @return Pointer to MainWindow
     */
    MainWindow *getMainWindow();

    /**
     * @brief setMainWindow
     * @param window
     */
    void setMainWindow(MainWindow *window);

private slots:

    /**
     * @brief on_buttonBox_accepted Function, which collects signal accepted
     */
    void on_buttonBox_accepted();

    /**
     * @brief onbuttonBox_rejected Function, which collets rejected signal
     */
    void onbuttonBox_rejected();

    /**
     * @brief mainWindow_new_triggered Function which collets signal trigger - new schema from MainWindow
     */
    void mainWindow_new_triggered();


private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    MainWindow *mainwindow = nullptr;

};

#endif // DIALOG_H

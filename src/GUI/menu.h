#ifndef FORM_H
#define FORM_H

#include "mainwindow.h"
#include "dialog.h"
#include "ui_menu.h"
#include "GraphicsScene.h"


namespace Ui {
class Form;
}

/**
 * @brief The Form class
 */
class Form : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Form Constructor of class Form
     * @param parent Parent window
     */
    explicit Form(QWidget *parent = 0);

    /**
     * @brief ~Form Destructor of class Form
     */
    ~Form();

private slots:

    /**
     * @brief on_pushButton_clicked Start new project
     */
    void on_pushButton_clicked();

    /**
     * @brief on_pushButton_3_clicked End program
     */
    void on_pushButton_3_clicked();

    void on_pushButton_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_windowTitleChanged(const QString &title);

private:
    /**
     * @brief ui GUI window
     */
    Ui::Form *ui;

};

#endif // FORM_H

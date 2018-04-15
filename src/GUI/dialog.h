#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "GraphicsScene.h"
#include "mainwindow.h"
#include "../LOGIC/Scheme.hpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_textEdit_windowTitleChanged(const QString &title);

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;

    /**
     * @brief scheme Logic scheme
     */
    Scheme *scheme;
};

#endif // DIALOG_H

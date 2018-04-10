#ifndef FORM_H
#define FORM_H

#include <QtWidgets>
#include <QDialog>
#include <QtCore>
#include <QtGui>
// asi treba pouzivat widgets lebo gui nepozna
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "mainwindow.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Form *ui;

};

#endif // FORM_H

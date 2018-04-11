#ifndef FORM_H
#define FORM_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QDebug>
#include <QToolBar>
#include <QGraphicsItem>

#include "mainwindow.h"
#include "ui_form.h"


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

#include "form.h"
#include "mainwindow.h"
#include "ui_form.h"
#include <QMessageBox>
#include <QDebug>
#include <QToolBar>
#include <QGraphicsItem>



Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    //vytvori mi nove okno
     MainWindow *mainwindow = new MainWindow();
     mainwindow->show();
     this->hide();
     this->close();


}

void Form::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Quit","Do you want to quit the game?",
                          QMessageBox::Yes | QMessageBox::No);
   if(reply == QMessageBox::Yes) {
   QApplication::quit();
   }
   else {
   qDebug() << "No is clicked";
   }

}

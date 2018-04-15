#include "menu.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{

    //vytvori mi nove okno
     Dialog *dialog = new Dialog();
     dialog->show();
     this->hide();
     this->close();

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

void Form::on_pushButton_windowTitleChanged(const QString &title)
{

}

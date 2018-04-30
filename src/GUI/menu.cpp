/* Autory : Juraj Kula , Michal Vako
 * Popis: Uvodne okno po zapnuti programu,
 * kde sa pomocou New mozme dostat k hlavnemu okno alebo pomocou Quit ukoncit program
 *                                   */

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
     dialog = new Dialog();
     dialog->show();

     QObject::connect(dialog->getUI()->buttonBox, SIGNAL(rejected()), this, SLOT(dialogRejected_showMenu()));

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

void Form::dialogRejected_showMenu() {
    this->show();
    dialog->hide();
    dialog->close();
}

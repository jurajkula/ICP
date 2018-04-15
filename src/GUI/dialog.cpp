#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::accept() {}

void Dialog::on_buttonBox_accepted()
{
    if (this->ui->lineEdit->text().isEmpty()) {
        this->ui->lineEdit->setStyleSheet("QLineEdit {background-color: red; color: white;}");
        return;
    }

     //vytvori mi nove okno
     MainWindow *mainwindow = new MainWindow(this->ui->lineEdit->text().toStdString());
     mainwindow->show();

     this->hide();
     this->done(QDialog::Accepted);
     this->close();
}

Ui::Dialog *Dialog::getUI() {
    return this->ui;
}

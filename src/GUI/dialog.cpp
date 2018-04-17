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

void Dialog::onbuttonBox_rejected() {
    this->hide();
    this->close();
}

void Dialog::on_buttonBox_accepted()
{
    if (this->ui->lineEdit->text().isEmpty()) {
        this->ui->lineEdit->setStyleSheet("QLineEdit {background-color: red; color: white;}");
        return;
    }

    if (mainwindow != nullptr) {
        mainwindow->hide();
        mainwindow->close();
    }


    //vytvori mi nove okno
    mainwindow = new MainWindow(this->ui->lineEdit->text().toStdString());
    mainwindow->show();

    QObject::connect(mainwindow->getUI()->actionNew_2, SIGNAL(triggered()), this, SLOT(mainWindow_new_triggered()));

    this->hide();
    this->done(QDialog::Accepted);
    this->close();
}

MainWindow *Dialog::getMainWindow() {
    return this->mainwindow;
}

void Dialog::setMainWindow(MainWindow *window) {
    this->mainwindow = window;
}

void Dialog::mainWindow_new_triggered() {
    Dialog *d = new Dialog();
    d->show();
    d->setMainWindow(this->mainwindow);

    QObject::connect(d->ui->buttonBox, SIGNAL(rejected()), this, SLOT(on_buttonBox_accepted()));

    this->close();
}

Ui::Dialog *Dialog::getUI() {
    return this->ui;
}

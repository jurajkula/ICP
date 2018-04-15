#include "portdataform.h"

portDataForm::portDataForm(QVBoxLayout *layout, std::vector<portDataForm *> *portDataForms, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portDataForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->l = layout;
    this->portDataForms = portDataForms;

    if (portDataForms->size() == 0) {
        this->ui->pushButton->hide();
    }

    this->ui->value->setValidator(new QDoubleValidator(0, 100, 10, this));
    this->ui->value->setText("0");
}

Ui::portDataForm* portDataForm::GetUI(){
    return this->ui;
}

void portDataForm::showButton() {
    this->ui->pushButton->show();
}

portDataForm::~portDataForm()
{
    delete ui;
}

void portDataForm::on_pushButton_clicked()
{
    if (portDataForms->size() == 1) {
        return;
    }

    for (unsigned int i = 0; i < portDataForms->size(); i++) {
        if (this == portDataForms->at(i)){
            portDataForms->erase(portDataForms->begin() + i);
        }
    }

    if (portDataForms->size() == 1) {
        portDataForms->back()->ui->pushButton->hide();
    }

    l->removeWidget(this);
    this->close();
}

#include "portform.h"
#include "ui_portform.h"

portForm::portForm(QVBoxLayout *layout, std::vector<portForm *> *portForms, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->l = layout;
    this->portForms = portForms;
}

portForm::~portForm()
{
    delete ui;
}

void portForm::on_pushButton_clicked()
{
    for (int i = 0; i < portForms->size(); i++) {
        if (this == portForms->at(i)){
            portForms->erase(portForms->begin() + i);
        }
    }
    l->removeWidget(this);
    this->close();
}

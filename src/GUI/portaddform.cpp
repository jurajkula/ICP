#include "portaddform.h"
#include "ui_portaddform.h"

portAddForm::portAddForm(QVBoxLayout *l, std::vector<portForm *> *portForms, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portAddForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->l = l;
    this->portForms = portForms;
}

portAddForm::~portAddForm()
{
    delete ui;
}

void portAddForm::on_pushButton_clicked()
{
    this->l->removeWidget(this);
    portForm *pF = new portForm(l, portForms);
    this->l->addWidget(pF);
    this->portForms->push_back(pF);

    this->l->addWidget(this);
}

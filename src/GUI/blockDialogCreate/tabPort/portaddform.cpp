#include "portaddform.h"

portAddForm::portAddForm(QVBoxLayout *l, std::vector<portPage *> *portPages, std::vector<portForm *> *portForms, portToolBox *box, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portAddForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->l = l;
    this->portPages = portPages;
    this->portForms = portForms;
    this->portBox = box;
}

portAddForm::~portAddForm()
{
    delete ui;
}

void portAddForm::on_pushButton_clicked()
{    
    this->l->removeWidget(this);
    portPage *pP = new portPage(portPages, portBox);
    portBox->addItem(pP, "Port");
    //this->portForms->push_back(pP);
    this->portPages->push_back(pP);

    this->l->addWidget(this);
}

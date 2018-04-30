/* Autory : Juraj Kula , Michal Vako
 * Popis:
 *                                   */

#include "portadddataform.h"

portAddDataForm::portAddDataForm(QVBoxLayout *l, std::vector<portDataForm *> *portDataForms, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portAddDataForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->l = l;
    this->portDataForms = portDataForms;
}

portAddDataForm::~portAddDataForm()
{
    delete ui;
}

void portAddDataForm::on_pushButton_clicked()
{
    portDataForms->front()->showButton();

    l->removeWidget(this);
    portDataForm *p = new portDataForm(l, portDataForms);
    l->addWidget(p);
    portDataForms->push_back(p);

    l->addWidget(this);
}

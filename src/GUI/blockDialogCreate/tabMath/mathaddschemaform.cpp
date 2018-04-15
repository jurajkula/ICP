#include "mathaddschemaform.h"

mathAddSchemaForm::mathAddSchemaForm(QVBoxLayout *l, std::vector<mathSchemaForm *> *mathForms, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mathAddSchemaForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->layout = l;
    this->mathForms = mathForms;
}

mathAddSchemaForm::~mathAddSchemaForm()
{
    delete ui;
}

Ui::mathAddSchemaForm *mathAddSchemaForm::getUI() {
    return this->ui;
}

void mathAddSchemaForm::on_pushButton_clicked()
{
    mathForms->front()->showButton();
    layout->removeWidget(this);

    mathSchemaForm *form = new mathSchemaForm(layout, mathForms);
    mathForms->push_back(form);
    layout->addWidget(form);
    layout->addWidget(this);
}

/* Autory : Juraj Kula , Michal Vako
 * Popis:
 *                                   */

#include "portform.h"

portForm::portForm(QToolBox *l,  QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->l = l;
    this->parent = parent;
}

portForm::~portForm()
{
    delete ui;
}

Ui::portForm* portForm::GetUI(){
    return this->ui;
}

void portForm::on_pushButton_clicked()
{
   /* l->removeItem(l->indexOf(parent));
    delete(parent);
    parent = NULL;*/
}

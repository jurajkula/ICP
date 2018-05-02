/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre port stránku - hlavička
*/

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

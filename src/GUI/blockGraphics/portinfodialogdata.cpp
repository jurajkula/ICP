/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre zobrazenie informačného dialógu nad portami
*/

#include "portinfodialogdata.h"

portInfoDialogData::portInfoDialogData(pData *d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portInfoDialogData)
{
    ui->setupUi(this);

    this->ui->Name->setText(QString::fromStdString(d->name));
    this->ui->Value->setText(QString::number(d->value));

    this->setFixedSize(this->size());
    //this->ui->verticalLayoutWidget->setStyleSheet("border: 1px solid black");
}

portInfoDialogData::~portInfoDialogData()
{
    delete ui;
}

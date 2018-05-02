/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul zobrazenie dát z bloku
*/

#include "rectangleinfodialogdata.h"
#include "ui_rectangleinfodialogdata.h"

rectangleInfoDialogData::rectangleInfoDialogData(rule *r, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rectangleInfoDialogData)
{
    ui->setupUi(this);

    this->ui->output->setText(QString::fromStdString(r->output));
    this->ui->schema->setText(QString::fromStdString(r->infoSchema));
    this->setFixedSize(this->size());
}

rectangleInfoDialogData::~rectangleInfoDialogData()
{
    delete ui;
}

Ui::rectangleInfoDialogData *rectangleInfoDialogData::getUi()
{
    return this->ui;
}

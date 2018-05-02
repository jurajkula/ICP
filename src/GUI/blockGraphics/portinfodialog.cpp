/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre zobrazenie informačného dialógu nad portami
*/

#include "portinfodialog.h"

portInfoDialog::portInfoDialog(port *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portInfoDialog)
{
    ui->setupUi(this);

    this->p = p;
    layout = new QHBoxLayout();

    prepareData();

    this->setLayout(layout);
}

portInfoDialog::~portInfoDialog()
{
    delete ui;
}

void portInfoDialog::setPos(QPointF pos) {
    if (p->getStatus() == INPUT) {
        this->move(pos.x() - this->width(), pos.y());
    }
    else {
        this->move(pos.x() + 30, pos.y());
    }
}

void portInfoDialog::prepareData() {
    this->clearLayout(true);

    if ((p->isConnected()) && (p->getStatus() == INPUT)) {        
        for (pData *d : p->getData()) {
            d->value = p->getConnection().p->returnData(p->returnPosData(d->name))->value;
            layout->addWidget(new portInfoDialogData(d));
        }
    }
    else {
        for (pData *d : p->getData()) {
                layout->addWidget(new portInfoDialogData(d));
            }
    }
}

void portInfoDialog::clearLayout(bool deleteWidgets)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        QLayout* childLayout = item->layout();
        if (childLayout)
            clearLayout(deleteWidgets);
        delete item;
    }
}

void portInfoDialog::showEvent(QShowEvent *event)
{
    prepareData();
    QWidget::showEvent(event);
}

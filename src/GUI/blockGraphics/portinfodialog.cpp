/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

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

    port *pointer;

    if ((p->isConnected()) && (p->getStatus() == INPUT)) {
        pointer = p->getConnection().p;
    }
    else {
        pointer = p;
    }

    for (pData *d : pointer->getData()) {
        layout->addWidget(new portInfoDialogData(d));
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

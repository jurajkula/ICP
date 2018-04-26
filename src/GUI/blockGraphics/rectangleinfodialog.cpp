#include "rectangleinfodialog.h"

rectangleInfoDialog::rectangleInfoDialog(Block *b, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rectangleInfoDialog)
{
    ui->setupUi(this);

    layout = new QVBoxLayout();

    for (rule r : b->getRules()) {
        layout->addWidget(new rectangleInfoDialogData(&r));
    }

    this->setLayout(layout);
}

rectangleInfoDialog::~rectangleInfoDialog()
{
    delete ui;
}

void rectangleInfoDialog::setPos(QPointF pos, int blockWidth) {
    this->move(pos.x() + blockWidth / 2 - this->width() / 2, pos.y() - this->height());
}

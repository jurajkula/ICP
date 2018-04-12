#include "createblock.h"
#include "ui_createblock.h"
#include "gBlock.h"
#include "portform.h"
#include "portaddform.h"

#include <QScrollArea>
#include <QVBoxLayout>

createBlock::createBlock(QGraphicsScene *scene, QPointF pos, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createBlock)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->scene = scene;
    this->pos = pos;

    QVBoxLayout *layout = new QVBoxLayout();
    ui->scrollAreaWidgetContents->setLayout(layout);

    portForm *pF = new portForm(layout, &portForms);
    portAddForm *pAF = new portAddForm(layout, &portForms);

    layout->addWidget(pF);
    portForms.push_back(pF);

    layout->addWidget(pAF);
}

createBlock::~createBlock()
{
    delete ui;
}

void createBlock::on_buttonBox_accepted()
{
    //TODO
    new gBlock(this->scene, pos);
}

void createBlock::on_buttonBox_rejected()
{
    this->close();
}

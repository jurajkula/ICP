#include "createblock.h"
#include "ui_createblock.h"
#include "gBlock.h"

createBlock::createBlock(QGraphicsScene *scene, QPointF pos, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createBlock)
{
    ui->setupUi(this);
    this->scene = scene;
    this->pos = pos;
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

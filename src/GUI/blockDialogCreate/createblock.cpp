#include "createblock.h"

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

    portToolBox *pTB = new portToolBox();
    portAddForm *pAF = new portAddForm(layout, &portPages, &portForms, pTB);

    portPage *w = new portPage(&portPages, pTB);
    portPages.push_back(w);

    pTB->addItem(w,"Port");
    layout->addWidget(pTB);
    layout->addWidget(pAF);
}

createBlock::~createBlock()
{
    delete ui;
}

void createBlock::on_buttonBox_accepted()
{

}

void createBlock::on_buttonBox_rejected()
{
    this->close();
}

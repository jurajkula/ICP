#ifndef CREATEBLOCK_H
#define CREATEBLOCK_H

#include "portform.h"

#include <QDialog>
#include <QGraphicsScene>

namespace Ui {
class createBlock;
}

class createBlock : public QDialog
{
    Q_OBJECT

public:
    explicit createBlock(QGraphicsScene *scene, QPointF pos, QWidget *parent = 0);
    ~createBlock();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::createBlock *ui;
    QGraphicsScene *scene;
    QPointF pos;
    std::vector<portForm *> portForms;
};

#endif // CREATEBLOCK_H

#ifndef RECTANGLEINFODIALOG_H
#define RECTANGLEINFODIALOG_H

#include <QVBoxLayout>
#include <QWidget>

#include <src/LOGIC/block.hpp>
#include "rectangleinfodialogdata.h"
#include "ui_rectangleinfodialog.h"

namespace Ui {
class rectangleInfoDialog;
}

class rectangleInfoDialog : public QWidget
{
    Q_OBJECT

public:
    explicit rectangleInfoDialog(Block *b, QWidget *parent = 0);
    ~rectangleInfoDialog();

    void setPos(QPointF pos, int blockWidth);

private:
    Ui::rectangleInfoDialog *ui;
    QVBoxLayout *layout;
};

#endif // RECTANGLEINFODIALOG_H

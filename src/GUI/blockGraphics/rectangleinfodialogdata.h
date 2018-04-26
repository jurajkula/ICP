#ifndef RECTANGLEINFODIALOGDATA_H
#define RECTANGLEINFODIALOGDATA_H

#include <QWidget>

#include <src/LOGIC/ICPmath.hpp>

namespace Ui {
class rectangleInfoDialogData;
}

class rectangleInfoDialogData : public QWidget
{
    Q_OBJECT

public:
    explicit rectangleInfoDialogData(rule *r, QWidget *parent = 0);
    ~rectangleInfoDialogData();

    Ui::rectangleInfoDialogData *getUi();

private:
    Ui::rectangleInfoDialogData *ui;
};

#endif // RECTANGLEINFODIALOGDATA_H

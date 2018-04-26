#ifndef PORTINFODIALOGDATA_H
#define PORTINFODIALOGDATA_H

#include <QWidget>
#include <src/LOGIC/port.hpp>
#include "ui_portinfodialogdata.h"

namespace Ui {
class portInfoDialogData;
}

class portInfoDialogData : public QWidget
{
    Q_OBJECT

public:
    portInfoDialogData(pData *d, QWidget *parent = 0);
    ~portInfoDialogData();

private:
    Ui::portInfoDialogData *ui;
};

#endif // PORTINFODIALOGDATA_H

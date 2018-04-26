#ifndef PORTINFODIALOG_H
#define PORTINFODIALOG_H

#include <QHBoxLayout>
#include <QWidget>
#include <src/LOGIC/port.hpp>
#include "ui_portinfodialog.h"
#include "portinfodialogdata.h"

namespace Ui {
class portInfoDialog;
}

class portInfoDialog : public QWidget
{
    Q_OBJECT

public:
    explicit portInfoDialog(port *p, QWidget *parent = 0);
    ~portInfoDialog();

    void setPos(QPointF pos);
protected:
    virtual void showEvent(QShowEvent *event) override;
    void clearLayout(bool deleteWidgets = true);
    void prepareData();
private:
    Ui::portInfoDialog *ui;
    QHBoxLayout *layout;
    port *p;
};

#endif // PORTINFODIALOG_H

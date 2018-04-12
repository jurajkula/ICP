#ifndef PORTADDFORM_H
#define PORTADDFORM_H

#include "portform.h"

#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class portAddForm;
}

class portAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit portAddForm(QVBoxLayout *,std::vector<portForm *> *portForms, QWidget *parent = 0);
    ~portAddForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::portAddForm *ui;
    QVBoxLayout *l;
    std::vector<portForm *> *portForms;
};

#endif // PORTADDFORM_H

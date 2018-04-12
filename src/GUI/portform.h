#ifndef PORTFORM_H
#define PORTFORM_H

#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class portForm;
}

class portForm : public QWidget
{
    Q_OBJECT

public:
    explicit portForm(QVBoxLayout *, std::vector<portForm *> *, QWidget *parent = 0);
    ~portForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::portForm *ui;
    QVBoxLayout *l;
    std::vector<portForm *> *portForms;
};

#endif // PORTFORM_H

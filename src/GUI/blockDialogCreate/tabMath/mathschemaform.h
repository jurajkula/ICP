#ifndef MATHSCHEMAFORM_H
#define MATHSCHEMAFORM_H

#include <QVBoxLayout>
#include <QWidget>

#include "ui_mathschemaform.h"
#include "../../../LOGIC/ICPmath.hpp"

namespace Ui {
class mathSchemaForm;
}

class mathSchemaForm : public QWidget
{
    Q_OBJECT

public:
    explicit mathSchemaForm(QVBoxLayout *layout, std::vector<mathSchemaForm *> *mathForms, QWidget *parent = 0);
    ~mathSchemaForm();

    /**
     * @brief showButton Support function, which
     */
    void showButton();

    /**
     * @brief getUI Support function, which returns UI
     * @return
     */
    Ui::mathSchemaForm *getUI();

private slots:
    void on_destroySchema_clicked();

    void on_mathSchema_editingFinished();

private:
    Ui::mathSchemaForm *ui;

    QVBoxLayout *layout;
    std::vector<mathSchemaForm *> *mathForms;
};

#endif // MATHSCHEMAFORM_H

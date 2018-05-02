/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre vzorcovú stránku - pridanie nového vzorca
*/

#ifndef MATHADDSCHEMAFORM_H
#define MATHADDSCHEMAFORM_H

#include "mathschemaform.h"
#include "ui_mathaddschemaform.h"

namespace Ui {
class mathAddSchemaForm;
}

/**
 * @brief The mathAddSchemaForm class
 */
class mathAddSchemaForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief mathAddSchemaForm Constructor of class
     * @param l Pointer to layout
     * @param mathForms Pointer to vector of math forms
     * @param parent Pointer to parent window
     */
    explicit mathAddSchemaForm(QVBoxLayout *l, std::vector<mathSchemaForm *> *mathForms, QWidget *parent = 0);
    ~mathAddSchemaForm();

    /**
     * @brief getUI Support function, which returns UI
     * @return
     */
    Ui::mathAddSchemaForm *getUI();

private slots:

    /**
     * @brief on_pushButton_clicked Function, which add other math form
     */
    void on_pushButton_clicked();

private:
    Ui::mathAddSchemaForm *ui;

    QVBoxLayout *layout;
    std::vector<mathSchemaForm *> *mathForms;
};

#endif // MATHADDSCHEMAFORM_H

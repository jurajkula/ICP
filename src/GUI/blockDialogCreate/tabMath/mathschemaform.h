/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre vzorcovú stránku
*/

#ifndef MATHSCHEMAFORM_H
#define MATHSCHEMAFORM_H

#include <QVBoxLayout>
#include <QWidget>

#include "ui_mathschemaform.h"
#include "../../../LOGIC/ICPmath.hpp"

namespace Ui {
class mathSchemaForm;
}

/**
 * @brief The mathSchemaForm class
 */
class mathSchemaForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief mathSchemaForm Constructor of the class
     * @param layout Pointer to box layout
     * @param mathForms Pointer to vector of math forms
     * @param parent Pointer to parent widget
     */
    explicit mathSchemaForm(QVBoxLayout *layout, std::vector<mathSchemaForm *> *mathForms, QWidget *parent = 0);
    ~mathSchemaForm();

    /**
     * @brief showButton Support function, which show delete button
     */
    void showButton();

    /**
     * @brief getUI Support function, which returns UI
     * @return
     */
    Ui::mathSchemaForm *getUI();

private slots:
    /**
     * @brief on_destroySchema_clicked Destroy schema
     */
    void on_destroySchema_clicked();

    /**
     * @brief on_mathSchema_editingFinished Function which edit style of formula
     */
    void on_mathSchema_editingFinished();

private:
    /**
     * @brief ui Pointer to UI
     */
    Ui::mathSchemaForm *ui;

    /**
     * @brief layout Pointer to layout of this widget
     */
    QVBoxLayout *layout;

    /**
     * @brief mathForms Pointer to vector of graphics schemas
     */
    std::vector<mathSchemaForm *> *mathForms;
};

#endif // MATHSCHEMAFORM_H

/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre port stránku - pridanie dát
*/

#ifndef PORTADDDATAFORM_H
#define PORTADDDATAFORM_H

#include "portdataform.h"
#include "ui_portadddataform.h"

namespace Ui {
class portAddDataForm;
}

/**
 * @brief The portAddDataForm class
 */
class portAddDataForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief portAddDataForm Constructor of class
     * @param l Pointer to layout
     * @param portDataForms Pointer to vector of port data forms
     * @param parent Parent window
     */
    explicit portAddDataForm(QVBoxLayout *l, std::vector<portDataForm *> *portDataForms, QWidget *parent = 0);
    ~portAddDataForm();

private slots:
    /**
     * @brief on_pushButton_clicked Function, which add new data form
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui Window GUI
     */
    Ui::portAddDataForm *ui;

    /**
     * @brief l Pointer to ToolBox layout
     */
    QVBoxLayout *l;

    /**
     * @brief portDataForms Pointer to vector of port data forms
     */
    std::vector<portDataForm *> *portDataForms;
};

#endif // PORTADDDATAFORM_H

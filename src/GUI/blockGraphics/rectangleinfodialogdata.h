/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul zobrazenie dát z bloku
*/

#ifndef RECTANGLEINFODIALOGDATA_H
#define RECTANGLEINFODIALOGDATA_H

#include <QWidget>

#include <src/LOGIC/ICPmath.hpp>

namespace Ui {
class rectangleInfoDialogData;
}

/**
 * @brief The rectangleInfoDialogData class
 */
class rectangleInfoDialogData : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief rectangleInfoDialogData Constructor of the class
     * @param r Pointer to rule
     * @param parent Parent widget
     */
    explicit rectangleInfoDialogData(rule *r, QWidget *parent = 0);
    ~rectangleInfoDialogData();

    /**
     * @brief getUi Function which returns UI
     * @return UI
     */
    Ui::rectangleInfoDialogData *getUi();

private:
    /**
     * @brief ui Pointer to UI
     */
    Ui::rectangleInfoDialogData *ui;
};

#endif // RECTANGLEINFODIALOGDATA_H

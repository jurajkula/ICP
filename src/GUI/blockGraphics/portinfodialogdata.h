/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre zobrazenie informačného dialógu nad portami
*/

#ifndef PORTINFODIALOGDATA_H
#define PORTINFODIALOGDATA_H

#include <QWidget>
#include <src/LOGIC/port.hpp>
#include "ui_portinfodialogdata.h"

namespace Ui {
class portInfoDialogData;
}

/**
 * @brief The portInfoDialogData class
 */
class portInfoDialogData : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief portInfoDialogData Constructor of the class
     * @param d Pointer to logic data
     * @param parent Parent widget
     */
    portInfoDialogData(pData *d, QWidget *parent = 0);
    ~portInfoDialogData();

private:
    Ui::portInfoDialogData *ui;
};

#endif // PORTINFODIALOGDATA_H

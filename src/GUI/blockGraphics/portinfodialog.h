/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre zobrazenie informačného dialógu nad portami
*/

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

/**
 * @brief The portInfoDialog class
 */
class portInfoDialog : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief portInfoDialog Constructor of the class
     * @param p Pointer to logic port
     * @param parent Pointer to parent widget
     */
    explicit portInfoDialog(port *p, QWidget *parent = 0);
    ~portInfoDialog();

    /**
     * @brief setPos Set new position. Position is computed with port position, pot size and this size
     * @param pos Port position
     */
    void setPos(QPointF pos);
protected:
    /**
     * @brief showEvent Default function, but more this function prepare data
     * @param event Show event
     */
    virtual void showEvent(QShowEvent *event) override;

    /**
     * @brief clearLayout Function which clear layout
     * @param deleteWidgets Bool vlaue, if widgets has to be also deleted
     */
    void clearLayout(bool deleteWidgets = true);

    /**
     * @brief prepareData Function which prepare data. If port is not connected use its data else use data of ports which is connected to.
     */
    void prepareData();
private:
    Ui::portInfoDialog *ui;
    QHBoxLayout *layout;
    port *p;
};

#endif // PORTINFODIALOG_H

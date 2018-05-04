/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul zobrazenie dát z bloku
*/

#ifndef RECTANGLEINFODIALOG_H
#define RECTANGLEINFODIALOG_H

#include <QVBoxLayout>
#include <QWidget>

#include <src/LOGIC/block.hpp>
#include "rectangleinfodialogdata.h"
#include "ui_rectangleinfodialog.h"

namespace Ui {
class rectangleInfoDialog;
}

/**
 * @brief The rectangleInfoDialog class
 */
class rectangleInfoDialog : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief rectangleInfoDialog Constructor of the class
     * @param b Pointer to block
     * @param parent Pointer to parent widget
     */
    explicit rectangleInfoDialog(Block *b, QWidget *parent = 0);
    ~rectangleInfoDialog();

    /**
     * @brief setPos Function which set position of this widget to computed position from Block position, block size and this size
     * @param pos New Position
     * @param blockWidth Block width
     */
    void setPos(QPointF pos, int blockWidth);

private:
    /**
     * @brief ui Pointer to UI
     */
    Ui::rectangleInfoDialog *ui;

    /**
     * @brief layout QVBox layout
     */
    QVBoxLayout *layout;
};

#endif // RECTANGLEINFODIALOG_H

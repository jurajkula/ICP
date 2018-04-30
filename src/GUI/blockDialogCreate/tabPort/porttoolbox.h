/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

#ifndef PORTTOOLBOX_H
#define PORTTOOLBOX_H

#include <QToolBox>
#include "ui_porttoolbox.h"

namespace Ui {
class portToolBox;
}

/**
 * @brief The portToolBox class
 */
class portToolBox : public QToolBox
{
    Q_OBJECT

public:
    /**
     * @brief portToolBox Constructor of class
     * @param parent Parent window
     */
    explicit portToolBox(QWidget *parent = 0);
    ~portToolBox();

private:
    /**
     * @brief ui GUI window
     */
    Ui::portToolBox *ui;
};

#endif // PORTTOOLBOX_H

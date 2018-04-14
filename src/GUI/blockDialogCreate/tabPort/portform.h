#ifndef PORTFORM_H
#define PORTFORM_H

#include "ui_portform.h"
#include "porttoolbox.h"
#include "portadddataform.h"

namespace Ui {
class portForm;
}

/**
 * @brief The portForm class
 */
class portForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief portForm Constructor of class
     * @param box Box of pages
     * @param parent Parent window
     */
    explicit portForm(QToolBox *box, QWidget *parent = 0);
    ~portForm();

    /**
     * @brief GetUI Support function, which return clss ui
     * @return Return UI
     */
    Ui::portForm* GetUI();

private slots:
    /**
     * @brief on_pushButton_clicked NOTHING TODO DELETE
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui Window GUI
     */
    Ui::portForm *ui;

    /**
     * @brief l Toolbox of pages
     */
    QToolBox *l;

    /**
     * @brief parent Parent widget
     */
    QWidget *parent;
};

#endif // PORTFORM_H

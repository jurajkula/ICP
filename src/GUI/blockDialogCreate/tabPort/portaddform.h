#ifndef PORTADDFORM_H
#define PORTADDFORM_H

#include "portpage.h"
#include "ui_portaddform.h"

namespace Ui {
class portAddForm;
}

/**
 * @brief The portAddForm class
 */
class portAddForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief portAddForm Constructor of class
     * @param l Box layout
     * @param portPages Pointer to vector of port pages
     * @param portForms Pointer to vector of port forms
     * @param box Pointer to ToolBox
     * @param parent Parent window
     */
    explicit portAddForm(QVBoxLayout *l, std::vector<portPage *> *portPages, std::vector<portForm *> *portForms,portToolBox *box, QWidget *parent = 0);
    ~portAddForm();

private slots:
    /**
     * @brief on_pushButton_clicked Function, which add new form
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui Window GUI
     */
    Ui::portAddForm *ui;

    /**
     * @brief l Layout
     */
    QVBoxLayout *l;

    /**
     * @brief portPages Pointer to vector of port pages
     */
    std::vector<portPage *> *portPages;

    /**
     * @brief portForms Pointer to vector of port forms
     */
    std::vector<portForm *> *portForms;

    /**
     * @brief portBox Pointer to box
     */
    portToolBox *portBox;
};

#endif // PORTADDFORM_H

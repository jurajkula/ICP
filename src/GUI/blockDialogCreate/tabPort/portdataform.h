#ifndef PORTDATAFORM_H
#define PORTDATAFORM_H

#include "ui_portdataform.h"

#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class portDataForm;
}

/**
 * @brief The portDataForm class
 */
class portDataForm : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief portDataForm Constructor of class
     * @param l ToolBox layout
     * @param portDataForms Pointer to vector of port data forms
     * @param parent Parent window
     */
    explicit portDataForm(QVBoxLayout *l, std::vector<portDataForm *> *portDataForms, QWidget *parent = 0);
    ~portDataForm();

    /**
     * @brief GetUI Support function, which returns window GUI
     * @return Window GUI
     */
    Ui::portDataForm* GetUI();

    /**
     * @brief showButton Support function, which show button
     */
    void showButton();

private slots:
    /**
     * @brief on_pushButton_clicked Function, which delete this form
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui Window GUI
     */
    Ui::portDataForm *ui;

    /**
     * @brief l ToolBox layout
     */
    QVBoxLayout *l;

    /**
     * @brief portDataForms Pointer to vector of port data forms
     */
    std::vector<portDataForm *> *portDataForms;
};

#endif // PORTDATAFORM_H

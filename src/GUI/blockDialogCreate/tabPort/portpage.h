#ifndef PORTPAGE_H
#define PORTPAGE_H

#include "ui_portpage.h"
#include "portform.h"

#include <QDebug>
#include <src/LOGIC/port.hpp>

namespace Ui {
class portPage;
}

/**
 * @brief The portPage class
 */
class portPage : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief portPage Constructor of class
     * @param portPages Vector of port pages
     * @param box Box Box of pages
     * @param parent Parent window
     */
    explicit portPage(std::vector<portPage *> *portPages, portToolBox *box, QWidget *parent = 0);
    portPage(std::vector<portPage *> *portPages, portToolBox *b, port *p, QWidget *parent = 0);
    ~portPage();

    /**
     * @brief getPortDataForms Support function, which returns vector of data forms
     * @return Vector of data forms
     */
    std::vector<portDataForm *> getPortDataForms();

    /**
     * @brief getUi Function, which return page UI
     * @return Page UI
     */
    Ui::portPage *getUi();

    /**
     * @brief getPortForm Function, which return portForm
     * @return Return port form
     */
    portForm * getPortForm();

private slots:
    /**
     * @brief destroy_page Function, which delete page from vector and GUI
     */
    void destroy_page();

private:
    /**
     * @brief ui window GUI
     */
    Ui::portPage *ui;

    /**
     * @brief portDataForms Pointer to vector of port data forms
     */
    std::vector<portDataForm *> portDataForms;

    /**
     * @brief portPages Pointer to vector of port pages
     */
    std::vector<portPage *> *portPages;

    /**
     * @brief box Tool box of pages
     */
    portToolBox *box;

    /**
     * @brief pF PortForm of page
     */
    portForm *pF;

};

#endif // PORTPAGE_H

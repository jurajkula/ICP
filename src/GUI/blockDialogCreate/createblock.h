#ifndef CREATEBLOCK_H
#define CREATEBLOCK_H

#include "ui_createblock.h"
#include "../gBlock.h"
#include "../../LOGIC/port.hpp"
#include "../../LOGIC/Scheme.hpp"
#include "tabPort/portaddform.h"

#include <QDialog>
#include <QGraphicsScene>
#include <QScrollArea>
#include <QTextBrowser>


namespace Ui {
class createBlock;
}

/**
 * @brief The createBlock class
 */
class createBlock : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief createBlock Constructor of class
     * @param scheme Pointer to logic scheme
     * @param scene Scene
     * @param pos Position
     * @param parent Parent window
     */
    explicit createBlock(Scheme *scheme, QGraphicsScene *scene, QPointF pos, QWidget *parent = 0);
    ~createBlock();

    /**
     * @brief setErrorMessage Support function, which seet error message to label
     * @param s Message
     */
    void setErrorMessage(std::string s);

    virtual void accept();
private slots:

    /**
     * @brief on_buttonBox_accepted Function, which collect signal from button accept
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_buttonBox_rejected Function, which grab signal from button reject
     */
    void on_buttonBox_rejected();

private:

    /**
     * @brief ui GUI of window
     */
    Ui::createBlock *ui;

    /**
     * @brief scene Scene
     */
    QGraphicsScene *scene;

    /**
     * @brief pos Position
     */
    QPointF pos;

    /**
     * @brief portForms Vector of port forms
     */
    std::vector<portForm *> portForms;

    /**
     * @brief portPages Vector of port pages
     */
    std::vector<portPage *> portPages;

    /**
     * @brief ports Vector of ports
     */
    std::vector<port*> ports;

    /**
     * @brief scheme Pointer to logic scheme
     */
    Scheme *scheme;
};

#endif // CREATEBLOCK_H

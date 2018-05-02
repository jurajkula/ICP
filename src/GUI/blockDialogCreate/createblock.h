/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre dialóg na vytvorenie blokov
*/

#ifndef CREATEBLOCK_H
#define CREATEBLOCK_H

#include "ui_createblock.h"
#include "../blockGraphics/gBlock.h"
#include "../../LOGIC/port.hpp"
#include "../../LOGIC/Scheme.hpp"
#include "tabPort/portaddform.h"
#include "tabMath/mathaddschemaform.h"

#include <QDialog>
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
     * @brief createBlock Constructor of class - new dialog
     * @param scheme Pointer to logic scheme
     * @param scene Scene
     * @param pos Position
     * @param parent Parent window
     */
    explicit createBlock(Scheme *scheme, QGraphicsScene *scene, QPointF pos, QWidget *parent = 0);

    /**
     * @brief createBlock Constructor of class - edit dialog
     * @param s Pointer to logic scheme
     * @param scene Scene
     * @param pos Position
     * @param block Pointer to block
     * @param parent Parent window
     */
    createBlock(Scheme *s, QGraphicsScene *scene, QPointF pos, Block *block, QWidget *parent = 0);
    ~createBlock();

    /**
     * @brief setErrorMessage Support function, which set error message to label
     * @param s Message
     */
    void setErrorMessage(std::string s);

    /**
     * @brief accept Rewrite function accept() - do nothing
     */
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

    /**
     * @brief mathForms Vector of math forms
     */
    std::vector<mathSchemaForm *> mathForms;

    /**
     * @brief rules Rules of block
     */
    std::vector<rule> rules;

    Block *oldblock = nullptr;
};

#endif // CREATEBLOCK_H

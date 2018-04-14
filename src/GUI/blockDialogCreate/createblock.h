#ifndef CREATEBLOCK_H
#define CREATEBLOCK_H

#include "ui_createblock.h"
#include "../gBlock.h"
#include "../../LOGIC/port.hpp"
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
     * @param scene Scene
     * @param pos Position
     * @param parent Parent window
     */
    explicit createBlock(QGraphicsScene *scene, QPointF pos, QWidget *parent = 0);
    ~createBlock();

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
};

#endif // CREATEBLOCK_H

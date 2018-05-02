/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre toolbox
*/

#include "porttoolbox.h"

portToolBox::portToolBox(QWidget *parent) :
    QToolBox(parent),
    ui(new Ui::portToolBox)
{
    ui->setupUi(this);
}

portToolBox::~portToolBox()
{
    delete ui;
}

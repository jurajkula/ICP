/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Hlavný modul programu, spúštanie celého programu
*/

#include "GUI/menu.h"
#include <QApplication>

/**
 * @brief main Main function of program
 * @param argc Arguments count
 * @param argv Pointer to char array
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form w;
    w.show();

    return a.exec();
}

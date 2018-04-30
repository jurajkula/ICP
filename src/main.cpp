/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

#include "GUI/menu.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form w;
    w.show();

    return a.exec();
}

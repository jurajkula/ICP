/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

#ifndef SAVE_H
#define SAVE_H

#include <QFile>
#include <QXmlStreamWriter>
#include <qgraphicsscene.h>

#include <src/LOGIC/Scheme.hpp>

class Save
{
public:
    Save(Scheme *scheme, QGraphicsScene *scene, QFile *file);
};

#endif // SAVE_H

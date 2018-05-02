/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre uloženie programu - program prevedie do xml formátu
*/

#ifndef SAVE_H
#define SAVE_H

#include <QFile>
#include <QXmlStreamWriter>
#include <qgraphicsscene.h>

#include <src/LOGIC/Scheme.hpp>
#include <src/GUI/blockGraphics/rectangle.h>

/**
 * @brief The Save class
 */
class Save
{
public:
    /**
     * @brief Save Constructor of Save class
     * @param scheme Pointer to logic scheme
     * @param scene Pointer to graphics scene
     * @param file Pointer to file
     */
    Save(Scheme *scheme, QGraphicsScene *scene, QFile *file);
};

#endif // SAVE_H

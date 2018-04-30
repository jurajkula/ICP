/* Autory : Juraj Kula , Michal Vasko
 * Popis: Sluzi na ukladanie akltualnej rozohranej hry/programu v xml formate
 *                                   */


#include "save.h"

#include <src/GUI/blockGraphics/rectangle.h>

Save::Save(Scheme *scheme, QGraphicsScene *scene, QFile *file)
{
    file->open(QIODevice::WriteOnly);

    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();

    xml.writeStartElement("SCHEME");
    xml.writeTextElement("Name", QString::fromStdString(scheme->getName()));

    for (QGraphicsItem *item : scene->items()) {
        Rectangle *r = qgraphicsitem_cast<Rectangle *>(item);
        if (!r)
            continue;

        xml.writeStartElement("BLOCK");
        xml.writeTextElement("ID", QString::number(r->getLogicBlock()->getID()));

        xml.writeStartElement("POSITION");
        xml.writeTextElement("X", QString::number(r->pos().x()));
        xml.writeTextElement("Y", QString::number(r->pos().y()));
        xml.writeEndElement();

        xml.writeStartElement("SCHEMAS");
        for (rule Rule : r->getLogicBlock()->getRules()) {
            xml.writeTextElement("OUTPUT", QString::fromStdString(Rule.output));
            xml.writeTextElement("RULE", QString::fromStdString(Rule.infoSchema));
        }
        xml.writeEndElement();

        xml.writeStartElement("PORTS");
        for (port *p : *(r->getLogicBlock()->getPorts())) {
            xml.writeStartElement("PORT");
                xml.writeTextElement("ID", QString::number(p->getUniqueID()));
                xml.writeTextElement("TYPE", QString::number(p->getStatus()));

                xml.writeStartElement("CONNECTION");
                if (p->getConnection().connected){
                    xml.writeTextElement("IS_CONNECTED", "TRUE");
                    xml.writeTextElement("CPORT", QString::number(p->getConnection().p->getUniqueID()));
                }
                else {
                    xml.writeTextElement("IS_CONNECTED", "FALSE");
                }
                xml.writeEndElement();

                xml.writeStartElement("DATA");
                for (pData d : p->getData()) {
                    xml.writeStartElement("D");
                    xml.writeTextElement("NAME", QString::fromStdString(d.name));
                    xml.writeTextElement("VALUE", QString::number(d.value));
                    xml.writeEndElement();
                }
                xml.writeEndElement();

            xml.writeEndElement();
        }
        xml.writeEndElement();


        xml.writeEndElement();
    }

    xml.writeEndElement();
    xml.writeEndDocument();

    file->close();
}

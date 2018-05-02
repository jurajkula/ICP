/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre načítavanie schém
*/

#include "load.h"
#include <QDomDocument>

Load::Load(QFile *file)
{
    QDomDocument doc;
    if ((!file->open(QFile::ReadOnly) || (!doc.setContent(file)))) {
        // TODO chyba
        return;
    }

    QDomElement root = doc.documentElement();
    QDomElement schemeName = root.firstChildElement("Name");
    mainwindow = new MainWindow(schemeName.text().toStdString());

    QDomNodeList blocks = root.elementsByTagName("BLOCK");

    for (int i = 0; i < blocks.count(); i++) {
        //std::vector<port *> listPorts;
        std::vector<port *> *listPorts = new std::vector<port *>();
        std::vector<rule> listRules;

        QDomElement blockID = blocks.at(i).firstChildElement("ID");
        QDomElement blockPos = blocks.at(i).firstChildElement("POSITION");
        QDomElement blockSchemes = blocks.at(i).firstChildElement("SCHEMES");
        QDomElement blockPorts = blocks.at(i).firstChildElement("PORTS");

        QDomElement blockPosX = blockPos.firstChildElement("X");
        QDomElement blockPosY = blockPos.firstChildElement("Y");

        QDomNodeList schemes = blockSchemes.elementsByTagName("S");
        for (int j = 0; j < schemes.count(); j++) {
            QDomElement schemeOutput = schemes.at(j).firstChildElement("OUTPUT");
            QDomElement schemeRule = schemes.at(j).firstChildElement("RULE");

            rule r;
            r.output = schemeOutput.text().toStdString();
            r.infoSchema = schemeRule.text().toStdString();
            r.tokens = splitStringFormula(schemeRule.text().toStdString());
            listRules.push_back(r);
        }

        QDomNodeList ports = blockPorts.elementsByTagName("PORT");
        for (int j = 0; j < ports.count(); j++) {

            QDomElement portID = ports.at(j).firstChildElement("ID");
            QDomElement portType = ports.at(j).firstChildElement("TYPE");

            QDomElement portConnection = ports.at(j).firstChildElement("CONNECTION");
            QDomElement portConnectionPort = portConnection.firstChildElement("CPORT");
            QDomElement portConnectionStatus = portConnection.firstChildElement("IS_CONNECTED");

            if (!portConnectionStatus.text().toStdString().compare("TRUE")) {
                LoadConnect l;
                l.source = portID.text().toInt();
                l.dest = portConnectionPort.text().toInt();
                listConnection.push_back(l);
            }

            port *p = new port(portType.text().toInt(), portID.text().toInt());

            QDomElement portData = ports.at(j).firstChildElement("DATA");
            QDomNodeList D = portData.elementsByTagName("D");

            for (int k = 0; k < D.count(); k++) {
                QDomElement dName = D.at(k).firstChildElement("NAME");
                QDomElement dValue = D.at(k).firstChildElement("VALUE");

                p->addData(CreateData(dName.text().toStdString(), dValue.text().toDouble()));
            }

            listPorts->push_back(p);
            //TODO struktura pre connect, spajanie neskor
        }

        Block *block = new Block(listPorts, listRules, blockID.text().toInt());
        block->setPortsID();

        mainwindow->getScheme()->blockAdd(block);
        new gBlock(mainwindow->getScheme(), mainwindow->getScene(), QPointF(blockPosX.text().toDouble(), blockPosY.text().toDouble()), block);
    }

    for (LoadConnect c : listConnection) {
        PortNode *source = mainwindow->getPortNodeByPortUniqueID(c.source);
        PortNode *dest = mainwindow->getPortNodeByPortUniqueID(c.dest);

        if (mainwindow->getScheme()->createConnection(source->getLogicPort(), dest->getLogicPort())) {
            Arrow *arrow = new Arrow(source, dest);
            mainwindow->getScene()->addItem(arrow);
        }
    }

    mainwindow->show();
}

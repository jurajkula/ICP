#include "load.h"

Load::Load(QFile *file)
{
    if (!file->open(QFile::ReadOnly | QFile::Text)) {
        // TODO chyba
        return;
    }

    /*
    QXmlStreamReader xml;
    xml.setDevice(file);
    xml.readNext();

    while(!xml.atEnd()) {
        if (!xml.isStartElement()) {
            xml.readNext();
            continue;
        }

        if (xml.name() == "SCHEME") {
            xml.readNext();
        }
        // NAME
        else if (xml.name() == "Name") {
            while(!xml.atEnd()) {
                if (xml.isEndElement()) {
                    xml.readNext();
                    break;
                }

                if (xml.isStartElement()) {
                    qDebug("NAME");
                    QString s = xml.readElementText();
                    qDebug(s.toStdString().data());
                    mainwindow = new MainWindow(s.toStdString());
                    xml.readNext();
                }
                else {
                    xml.readNext();
                }
            }
        }
        // BLOCK
        else if (xml.name() == "BLOCK"){
            qDebug("BLOCK");
            Block *block;
            int blockID;
            int blockPosX;
            int blockPosY;

            while(!xml.atEnd()) {
                if(!xml.isStartElement()) {
                    xml.readNext();
                    continue;
                }
                if (xml.name() == "ID") {
                    while(!xml.atEnd()) {
                        if (xml.isEndElement()) {
                            xml.readNext();
                            break;
                        }

                        if (!xml.isStartElement()) {
                            xml.readNext();
                        }
                        else {
                            qDebug("BLOCK ID");
                            QString s = xml.readElementText();
                            qDebug(s.toStdString().data());
                            blockID = s.toInt();
                            xml.readNext();
                        }
                    }
                }
                else if(xml.name() == "POSITION") {
                    while(!xml.atEnd()) {
                        if (!xml.isStartElement()) {
                            xml.readNext();
                            continue;
                        }
                        if (xml.name() == "X"){
                            while(!xml.atEnd()) {
                                if (xml.isEndElement()) {
                                    xml.readNext();
                                    break;
                                }

                                if (!xml.isStartElement()) {
                                    xml.readNext();
                                }
                                else {
                                    qDebug("BLOCK POS X");
                                    QString s = xml.readElementText();
                                    qDebug(s.toStdString().data());
                                    blockPosX = s.toInt();
                                    xml.readNext();
                                }
                            }
                        }
                        else if (xml.name() == "Y") {
                            while(!xml.atEnd()) {
                                if (xml.isEndElement()) {
                                    xml.readNext();
                                    break;
                                }

                                if (!xml.isStartElement()) {
                                    xml.readNext();
                                }
                                else {
                                    qDebug("BLOCK POS Y");
                                    QString s = xml.readElementText();
                                    qDebug(s.toStdString().data());
                                    blockPosY = s.toInt();
                                    xml.readNext();
                                }
                            }
                        }
                        else {
                            xml.readNext();
                            break;
                        }
                    }
                }
                else if(xml.name() == "SCHEMAS") {
                            xml.readNext();
                            break;
                }
                else if (xml.name() == "PORTS") {
                            xml.readNext();
                            break;
                }
                else {
                    xml.readNext();
                    break;
                }
            }
        }

        else {
            xml.readNext();
        }
    }

    mainwindow->show();*/
}

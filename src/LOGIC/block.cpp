/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */


//
// Created by jurajkula on 24.3.2018.
//

#include "block.hpp"

Block::Block() = default;

Block::Block(std::vector<port *> *ports, std::vector<rule> r, int id) {
    this->ports = ports;
    this->rules = std::move(r);
    this->ID = id;

    for (port *p : *ports) {
        if(p->getStatus() == INPUT) {
            this->portsInputCount++;
        }
        else {
            this->portsOutputCount++;
        }
    }
}

std::vector<port *> *Block::getPorts() {
    return this->ports;
}

std::vector<rule> Block::getRules() {
    return this->rules;
}

// TODO compute data
bool Block::execute() {
    for (port *p : *ports) {
        if ((p->getStatus() == INPUT) && (p->isConnected())) {
            if (!p->isUsed())
                return false;
        }
    }

    for (rule r : this->rules) {
        double value = runComputing(&r, r.tokens, *ports);
        for (port *p : *ports) {
            if (p->findData(r.output)) {
                p->setDataValue(r.output, value);
            }
        }
    }

    for (port *p : *ports) {
        p->changeUsed(true);
        if (p->isConnected()) {
            p->getConnection().p->changeUsed(true);
        }
    }
    this->executed = true;

    return true;
}

int Block::getID() {
    return this->ID;
}

void Block::setID(int i) {
    this->ID = i;
}

void Block::setPortsID() {
    for (port *p : *ports) {
        p->setID(this->ID);
    }
}

int Block::getPortsInputCount() {
    return this->portsInputCount;
}

int Block::getPortsOutputCount() {
    return this->portsOutputCount;
}

void Block::setRules(std::vector<rule> rules)
{
    this->rules = rules;
}

void Block::setPorts(std::vector<port *> *ports)
{
    this->ports = ports;

    this->portsInputCount = this->portsOutputCount = 0;

    for (port *p : *ports) {
        if(p->getStatus() == INPUT) {
            this->portsInputCount++;
        }
        else {
            this->portsOutputCount++;
        }
    }
}

bool Block::getExecution()
{
    return this->executed;
}

void Block::setExecuted(bool b)
{
    this->executed = b;
}

void Block::defaultExecution() {
    this->executed = false;
    for (port *p : *ports) {
        p->changeUsed(false);
    }
}

void Block::deleteAll() {
    for (port *p : *ports) {
        p->deleteAll();
        delete(p);
        p = nullptr;
    }
    ports->clear();
    rules.clear();
}

/* Autory : Juraj Kula , Michal Vasko
 * Popis:
 *                                   */

//
// Created by jurajkula on 24.3.2018.
//

#include "Scheme.hpp"


Scheme::Scheme(std::string name) {
    this->name = std::move(name);
}

void Scheme::blockAdd(Block *b) {
    this->blocks.push_back(b);
}

void Scheme::blockDelete(Block *b) {
    for (unsigned long i = 0; i < this->blocks.size(); i++) {
        if (this->blocks.at(i) == b) {
            Block *bb = this->blocks.at(i);
            this->blocks.at(i)->deleteAll();
            this->blocks.erase(this->blocks.begin() + i);
            delete(bb);
            bb = nullptr;
        }
    }
}

//TODO  find blocks
bool Scheme::blockFind(Block *) {
    return false;
}

std::string Scheme::getName() {
    return this->name;
}

void Scheme::setName(std::string s) {
    this->name = s;
}

void Scheme::destroyConnection(port *pOUT, port *pIN) {
    pOUT->destroyConnection();
    pIN->destroyConnection();
}

bool Scheme::cycleConnection(port *pOUT, port *pIN) {
    for (Block *b : blocks) {
        if (b->getID() != pOUT->getID())
            continue;

        for(port *p : *(b->getPorts())) {
            if ((p->isConnected()) && (p->getStatus() == INPUT)) {
                if (pIN == p) {
                    return true;
                }
                else {
                    if (cycleConnection(p->getConnection().p, pIN)) {
                        return true;
                    }
                }
            }
            else if ((!p->isConnected()) && (p->getStatus() == INPUT)) {
                if (pIN == p) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Scheme::createConnection(port *pOUT, port *pIN) {
    if (pIN->isConnected() || pOUT->isConnected())
        return false;

    if (pIN->getData().size() != pOUT->getData().size())
        return false;

    if ((pIN->getStatus() != INPUT) || (pOUT->getStatus() != OUTPUT))
        return false;

    if (pIN->getID() == pOUT->getID())
        return false;

    if (cycleConnection(pOUT, pIN))
        return false;

    pIN->setConnection(pOUT);
    pOUT->setConnection(pIN);

    return true;
}

bool Scheme::compute() {
    //([a-zA-Z][a-zA-z0-9]*|[1-9][0-9]*)
    for (Block *b : blocks) {

        if (b->getExecution())
            continue;

        if (b->execute())
            break;
    }
    return true;
}

int Scheme::generatePortID() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, 10000);

    int id = 0;
    bool found = false;
    while(true) {
        id = dist(mt);
        for (Block *b: this->blocks) {
            for (port *p : *(b->getPorts())){
                if(p->getUniqueID() == id) {
                    found = true;
                    break;
                }
            }
        }
        if(found) {
            found = !found;
        }
        else {
            break;
        }
    }
    return id;
}

int Scheme::generateID() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, 10000);

    int id = 0;
    bool found = false;
    while(true) {
        id = dist(mt);
        for (Block *b: this->blocks) {
            if(b->getID() == id) {
                found = true;
                break;
            }
        }
        if(found) {
            found = !found;
        }
        else {
            break;
        }
    }
    return id;
}

port *Scheme::getPortByUniqueID(int ID) {
    for (Block *b : blocks) {
        for (port *p : *(b->getPorts())) {
            if (p->getUniqueID() == ID) {
                return p;
            }
        }
    }

    return nullptr;
}

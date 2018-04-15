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
            this->blocks.erase(this->blocks.begin() + i);
        }
    }
}

//TODO  find blocks
bool Scheme::blockFind(Block *b) {
    return false;
}

std::string Scheme::getName() {
    return this->name;
}

void Scheme::setName(std::string s) {
    this->name = s;
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

    pIN->setConnection(pOUT);
    pOUT->setConnection(pIN);

    return true;
}

bool Scheme::compute() {
    //([a-zA-Z][a-zA-z0-9]*|[1-9][0-9]*)
    return false;
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

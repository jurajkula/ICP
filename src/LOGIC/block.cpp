//
// Created by jurajkula on 24.3.2018.
//

#include "block.hpp"

Block::Block() = default;

Block::Block(std::vector<port *> port, std::vector<rule> r, int id) {
    this->ports = std::move(port);
    this->rules = std::move(r);
    this->ID = id;
}

std::vector<port *> Block::getPorts() {
    return this->ports;
}

std::vector<rule> Block::getRules() {
    return this->rules;
}

// TODO compute data
bool Block::execute() {



    return false;
}

int Block::getID() {
    return this->ID;
}

void Block::setID(int i) {
    this->ID = i;
}

void Block::setPortsID() {
    for (port *p : this->ports) {
        p->setID(this->ID);
    }
}

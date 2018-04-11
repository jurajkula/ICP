//
// Created by jurajkula on 24.3.2018.
//

#include "block.hpp"

block::block() = default;

block::block(std::vector<port *> port, std::vector<rule> r, int id) {
    this->ports = std::move(port);
    this->rules = std::move(r);
    this->ID = id;
}

std::vector<port *> block::getPorts() {
    return this->ports;
}

std::vector<rule> block::getRules() {
    return this->rules;
}

// TODO compute data
bool block::execute() {



    return false;
}

int block::getID() {
    return this->ID;
}

void block::setID(int i) {
    this->ID = i;
}

void block::setPortsID() {
    for (port *p : this->ports) {
        p->setID(this->ID);
    }
}

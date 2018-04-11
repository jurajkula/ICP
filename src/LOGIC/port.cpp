//
// Created by jurajkula on 24.3.2018.
//

#include "port.hpp"

port::port(int status) {
    this->connect.connected = false;
    this->status = status;
}

bool port::findData(std::string s) {
    for(data d : this->type) {
        if (d.name == s)
            return true;
    }
    return false;
}

data port::returnData(std::string s) {
    for(data d : this->type) {
        if (d.name == s)
            return d;
    }
}

bool port::addData(data d) {
    if (!findData(d.name)) {
        type.push_back(d);
        return true;
    }
    return false;
}

std::vector<data> port::getData() {
    return this->type;
}

bool port::isUsed() {
    return this->used;
}

void port::changeUsed() {
    this->used = !this->used;
}

bool port::isConnected() {
    return this->connect.connected;
}

void port::changeConnection() {
    this->connect.connected = !this->connect.connected;
}

port::connection port::getConnection() {
    return this->connect;
}

void port::setConnection(port *p) {
    this->connect.p = p;
    this->changeConnection();
}

int port::getStatus() {
    return this->status;
}

void port::setStatus(int s) {
    this->status = s;
}

int port::getID() {
    return this->ID;
}

void port::setID(int i) {
    this->ID = i;
}

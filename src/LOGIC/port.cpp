//
// Created by jurajkula on 24.3.2018.
//

#include "port.hpp"

pData CreateData(std::string name, double value) {
    pData d;
    d.name = name;
    d.value = value;
    return d;
}

port::port(int status) {
    this->connect.connected = false;
    this->status = status;
}

bool port::findData(std::string s) {
    for(pData d : this->type) {
        if (d.name == s)
            return true;
    }
    return false;
}

pData port::returnData(std::string s) {
    pData r;
    for(pData d : this->type) {
        if (d.name == s)
            r = d;
    }
    return r;
}

bool port::addData(pData d) {
    if (!findData(d.name)) {
        type.push_back(d);
        return true;
    }
    return false;
}

std::vector<pData> port::getData() {
    return this->type;
}

void port::clearData() {
    this->type.clear();
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

void port::destroyConnection() {
    this->connect.p = nullptr;
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

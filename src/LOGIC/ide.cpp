//
// Created by jurajkula on 24.3.2018.
//

#include <cstdlib>
#include "ide.hpp"

// TODO main structure of program, GUI, main control items
ide::ide() = default;
ide::~ide() = default;

scheme* ide::newScheme(std::string name) {
    return new scheme(name);
}

//TODO
bool ide::saveScheme() {
    return false;
}

//TODO
bool ide::loadScheme() {
    return false;
}

void ide::exitIDE() {
    delete this;
}

//TODO start compute
void ide::run() {

}

//TODO debbuging
void ide::debug() {

}
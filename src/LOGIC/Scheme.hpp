//
// Created by jurajkula on 24.3.2018.
//

#ifndef ICP_SCHEME_HPP
#define ICP_SCHEME_HPP

#include <utility>
#include <random>
#include <iostream>
#include <string>
#include "block.hpp"

class Scheme {
public:
    explicit Scheme(std::string);

    void blockAdd(block*);
    void blockDelete(block*);
    bool blockFind(block*);
    std::string getName();
    void setName(std::string);
    bool createConnection(port*,port*);
    bool compute();

    int generateID();

private:
    std::string name;
    std::vector<block *> blocks;
};


#endif //ICP_SCHEME_HPP

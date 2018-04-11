//
// Created by jurajkula on 24.3.2018.
//

#ifndef ICP_BLOCK_HPP
#define ICP_BLOCK_HPP

#include <utility>
#include <vector>
#include "ICPmath.hpp"


class block {
public:
    block();
    explicit block(std::vector<port *>, std::vector<rule>, int);

    std::vector<port *> getPorts();
    std::vector<rule> getRules();

    bool execute();

    int getID();
    void setID(int);
    void setPortsID();

private:
    std::vector<port *> ports;
    std::vector<rule> rules;
    int ID;
};


#endif //ICP_BLOCK_HPP

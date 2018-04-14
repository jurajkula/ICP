//
// Created by jurajkula on 24.3.2018.
//

#ifndef ICP_BLOCK_HPP
#define ICP_BLOCK_HPP

#include <utility>
#include <vector>
#include "ICPmath.hpp"

/**
 * @brief The block class
 */
class block {
public:
    /**
     * @brief block Default constructor
     */
    block();

    /**
     * @brief block Constructor of block
     * @param ports Vector of ports
     * @param rules Vector of rules
     * @param ID Generated block ID
     */
    explicit block(std::vector<port *> ports, std::vector<rule> rules, int ID);

    /**
     * @brief getPorts Function, which return vector of ports
     * @return Vector of ports
     */
    std::vector<port *> getPorts();

    /**
     * @brief getRules Function, which return vector of rules
     * @return Vector of rules
     */
    std::vector<rule> getRules();

    /**
     * @brief execute Function, which start block computing
     * @return Return TRUE, if computing as successful else return FALSE
     */
    bool execute();

    /**
     * @brief getID Function, which return block ID
     * @return Return block ID
     */
    int getID();

    /**
     * @brief setID Function, which set block ID
     * @param id New ID
     */
    void setID(int id);

    /**
     * @brief setPortsID Function, which set same ID to all ports. (ID is same as block ID)
     */
    void setPortsID();

private:
    /**
     * @brief ports Vector of ports
     */
    std::vector<port *> ports;

    /**
     * @brief rules Vector of rules
     */
    std::vector<rule> rules;

    /**
     * @brief ID Block ID
     */
    int ID;
};


#endif //ICP_BLOCK_HPP

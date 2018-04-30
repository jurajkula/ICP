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

/**
 * @brief The Scheme class
 */
class Scheme {
public:

    /**
     * @brief Scheme Constructor this class
     * @param s Name of scheme
     */
    explicit Scheme(std::string s);

    /**
     * @brief blockAdd Function, which add block to vector
     * @param b Pointer to block
     */
    void blockAdd(Block *b);

    /**
     * @brief blockDelete Function, which delete block from vector
     * @param b Pointer to block
     */
    void blockDelete(Block *b);

    /**
     * @brief blockFind Function, which find block in vector
     * @param b Pointer to block
     * @return Return TRUE, if block was founded, else return FALSE
     */
    bool blockFind(Block *b);

    /**
     * @brief getName Support function, which return name of the scheme
     * @return Name of the scheme as std::string
     */
    std::string getName();

    /**
     * @brief setName Support function, wchich set name of the scheme
     * @param s New name of the scheme
     */
    void setName(std::string s);

    void destroyConnection(port *pOUT, port *pIN);
    bool cycleConnection(port *pOUT, port *pIN);

    /**
     * @brief createConnection Function, which set connection between 2 ports
     * @param p1 Output port
     * @param p2 Input port
     * @return Return TRUE, if was possible create connection, else return FALSE
     */
    bool createConnection(port *out, port *in);

    /**
     * @brief compute Function, which run computing
     * @return Return TRUE, if computation was OK, else return FALSE
     */
    bool compute();

    /**
     * @brief generateID Support function, which generate ID.
     * @return Generated ID
     */
    int generateID();


    int generatePortID();
private:
    /**
     * @brief name Name of the scheme
     */
    std::string name;

    /**
     * @brief blocks Vector of blocks
     */
    std::vector<Block *> blocks;
};


#endif //ICP_SCHEME_HPP

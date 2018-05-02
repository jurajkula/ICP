/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Schéma blokov, udržuje logickú štruktúru blokov
*/

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
     * @brief Scheme Constructor of this class
     * @param s Name of scheme
     */
    explicit Scheme(std::string s);

    /**
     * @brief blockAdd Function, which add block to vector of blocks
     * @param b Pointer to block, which will be added to vector
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

    /**
     * @brief destroyConnection Function, which cancel connection between ports
     * @param pOUT  Pointer to output(source) port
     * @param pIN   Pointer to input(destination) port
     */
    void destroyConnection(port *pOUT, port *pIN);

    /**
     * @brief cycleConnection Function, which control cycling (block cannot be connected with block, which is directly or indirectly connected to it)
     * @param pOUT  Pointer to output(source) port
     * @param pIN   Pointer to input(destination) port
     * @return Return TRUE, if blocks are connected, else return FALSE
     */
    bool cycleConnection(port *pOUT, port *pIN);

    /**
     * @brief createConnection Function, which set connection between 2 ports and run some control between them
     * @param p1 Output port
     * @param p2 Input port
     * @return Return TRUE, if it was possible create connection, else return FALSE
     */
    bool createConnection(port *out, port *in);

    /**
     * @brief compute Function, which run computing
     * @return Return TRUE, if computation was OK, else return FALSE
     */
    bool compute();

    /**
     * @brief generateID Support function, which generate unique block ID.
     * @return Generated ID
     */
    int generateID();

    /**
     * @brief generatePortID Support function, wchich generate unique port ID.
     * @return Generated ID
     */
    int generatePortID();

    /**
     * @brief getPortByUniqueID Support function, which returns pointer to port, which was found via its ID
     * @param ID ID of wanted port
     * @return Pointer to port
     */
    port *getPortByUniqueID(int ID);
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

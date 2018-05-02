/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre logické bloky a funcie pre prácu s nimi
*/

#ifndef ICP_BLOCK_HPP
#define ICP_BLOCK_HPP

#include <utility>
#include <vector>
#include "ICPmath.hpp"

/**
 * @brief The Block class
 */
class Block {
public:
    /**
     * @brief Block Default constructor
     */
    Block();

    /**
     * @brief Block Constructor of block
     * @param ports Vector of ports
     * @param rules Vector of rules
     * @param ID Generated block ID
     */
    explicit Block(std::vector<port *> *ports, std::vector<rule> rules, int ID);

    /**
     * @brief getPorts Function, which return vector of ports
     * @return Vector of ports
     */
    std::vector<port *> *getPorts();

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

    /**
     * @brief getPortsInputCount Support function which returns input ports count
     * @return Count of input ports
     */
    int getPortsInputCount();

    /**
     * @brief getPortsOutputCount Support function which return output ports count
     * @return Count of outputports
     */
    int getPortsOutputCount();

    /**
     * @brief setRules Function which set rules
     * @param rules Vector of rules
     */
    void setRules(std::vector<rule> rules);

    /**
     * @brief setPorts Function which set ports
     * @param ports Vector of ports
     */
    void setPorts(std::vector<port *> *ports);

    /**
     * @brief getExecution Function which return state, if block was computed
     * @return State of computation
     */
    bool getExecution();

    /**
     * @brief setExecuted Function which change if block was computed or not
     * @param b State
     */
    void setExecuted(bool b);

    /**
     * @brief defaultExecution Function, which set computation state to default value
     */
    void defaultExecution();

    /**
     * @brief deleteAll Function which delete all ports, rules and free their memory
     */
    void deleteAll();
private:
    /**
     * @brief ports Vector of ports
     */
    std::vector<port *> *ports;

    /**
     * @brief rules Vector of rules
     */
    std::vector<rule> rules;

    /**
     * @brief ID Block ID
     */
    int ID;

    int portsInputCount = 0;
    int portsOutputCount = 0;
    bool executed = false;
};


#endif //ICP_BLOCK_HPP

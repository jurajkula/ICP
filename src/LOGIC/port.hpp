/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Logický modul portov, funkcie pre prácu s portami
*/

#ifndef ICP_PORT_HPP
#define ICP_PORT_HPP

#include <string>
#include <vector>

/**
 * @brief The data struct
 */
struct pData {
    /**
     * @brief name Name of var
     */
    std::string name;

    /**
     * @brief value Value of var
     */
    double value;
};

/**
 * @brief The portStatus enum
 */
enum portStatus{
    INPUT,
    OUTPUT
};

/**
 * @brief CreateData Support function, which create data
 * @param name Name of var
 * @param value Value of var
 * @return Return pointer to created data
 */
pData *CreateData(std::string name, double value);

/**
 * @brief The port class
 */
class port {
public:

    /**
     * @brief port Constructor of class port
     * @param status Status of the port (INPUT/OUTPUT)
     * @param uniqueID  Generated port ID
     */
    explicit port(int status, int uniqueID);

    /**
     * @brief setDataValue Support function, which find Data via name and change value
     * @param s Data name
     * @param value Data value
     */
    void setDataValue(std::string s, double value);

    /**
     * @brief findData Support function, which finds data in a vector
     * @param s Name of var
     * @return Return TRUE, if data wos founded, else return FALSE
     */
    bool findData(std::string s);

    /**
     * @brief returnData Support function, which finds data in a vector and return them
     * @param s Name of var
     * @return Return data
     */
    pData *returnData(std::string s);

    /**
     * @brief returnData Support function, which finds data in a vector and return them
     * @param pos Position of var
     * @return Return data
     */
    pData *returnData(unsigned int pos);

    /**
     * @brief returnPosData Support function, which find data via data name and return its position
     * @param s Data name
     * @return Position of data
     */
    unsigned int returnPosData(std::string s);

    /**
     * @brief addData Support function, which add data to vector and return successful state
     * @param d Data, which will be added to vector
     * @return Return TRUE, if data was successfuly added, alese return FALSE
     */
    bool addData(pData *d);

    /**
     * @brief clearData Support function, which clear all data
     */
    void clearData();

    /**
     * @brief getData Function, which return vector of data
     * @return Return data
     */
    std::vector<pData *> getData();

    /**
     * @brief isUsed Support function, which return state, if port is used. (using at computing)
     * @return Return TRUE, if port was used, else return FALSE
     */
    bool isUsed();

    /**
     * @brief changeUsed Support function, which change using state to opposite value
     * @param used State if port was computing
     */
    void changeUsed(bool used);

    /**
     * @brief The connection struct
     */
    struct connection {

        /**
         * @brief p Pointer to other port
         */
        port *p;

        /**
         * @brief connected State, if ports are connected
         */
        bool connected;
    };

    /**
     * @brief getConnection Funcitno, which return connection
     * @return Connection of port
     */
    connection getConnection();

    /**
     * @brief setConnection Function, which connects this port with other and set connection status to TRUE
     * @param p Pointer to other port
     */
    void setConnection(port *p);

    /**
     * @brief isConnected Support function, which return if port is connected
     * @return Return TRUE, if port is connected, else return FALSE
     */
    bool isConnected();

    /**
     * @brief changeConnection Support function, which change state of connection to opposite value
     */
    void changeConnection();

    /**
     * @brief destroyConnection Function which cancel port connection
     */
    void destroyConnection();

    /**
     * @brief getStatus Function, which return status
     * @return Return status
     */
    int getStatus();

    /**
     * @brief setStatus Functin, which set new status
     * @param status New status
     */
    void setStatus(int status);

    /**
     * @brief getID Support function, which return Port ID
     * @return Port ID
     */
    int getID();

    /**
     * @brief setID Supprt function, which set a new port ID
     * @param ID A new ID
     */
    void setID(int ID);

    /**
     * @brief getUniqueID Function which get port unique ID
     * @return unique ID
     */
    int getUniqueID();

    /**
     * @brief setUniqueID Function which set port unique ID
     * @param uniqueID New unique ID
     */
    void setUniqueID(int uniqueID);

    /**
     * @brief deleteAll Function, which delete data, connection -> free memory
     */
    void deleteAll();
private:
    /**
     * @brief type vector of all data
     */
    std::vector<pData *> type;

    /**
     * @brief used Var, i port is used, default is set to false
     */
    bool used = false;

    /**
     * @brief connect connection struct
     */
    connection connect;

    /**
     * @brief status Port status
     */
    int status;

    /**
     * @brief ID Port ID, default is set to 0
     */
    int ID = 0;

    /**
     * @brief uniqueID Port unique ID, default is set to 0
     */
    int uniqueID = 0;
};


#endif //ICP_PORT_HPP

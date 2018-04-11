//
// Created by jurajkula on 24.3.2018.
//

#ifndef ICP_PORT_HPP
#define ICP_PORT_HPP

#include <string>
#include <vector>

struct data {
    std::string name;
    double value;
};

enum portStatus{
    OUTPUT,
    INPUT
};

class port {
public:
    explicit port(int);

    bool findData(std::string);

    data returnData(std::string);
    bool addData(data);
    std::vector<data> getData();

    bool isUsed();
    void changeUsed();

    struct connection {
        port *p;
        bool connected;
    };

    connection getConnection();
    void setConnection(port *);
    bool isConnected();
    void changeConnection();

    int getStatus();
    void setStatus(int);

    int getID();
    void setID(int);


private:
    std::vector<data> type;
    bool used = false;
    connection connect;
    int status;
    int ID = 0;
};


#endif //ICP_PORT_HPP

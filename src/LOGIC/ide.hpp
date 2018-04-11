//
// Created by jurajkula on 24.3.2018.
//

#ifndef ICP_IDE_HPP
#define ICP_IDE_HPP

#include "Scheme.hpp"

class ide {
public:
    ide();
    virtual ~ide();

    Scheme* newScheme(std::string);
    bool saveScheme();
    bool loadScheme();
    void exitIDE();
    void run();
    void debug();
private:
};


#endif //ICP_IDE_HPP

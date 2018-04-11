//
// Created by jurajkula on 8.4.2018.
//

#ifndef TEST_ICPMATH_HPP
#define TEST_ICPMATH_HPP

#include <iostream>
#include <utility>
#include <cmath>
#include <string>
#include <regex>
#include "port.hpp"

enum sMathTypes {
    sMathType_OP,
    sMathType_VAR,
    sMathType_CONST
};

enum table {
    TE,
    TL,
    TM,
    TX,
};

struct sMath {
    std::string value;
    int type;
    bool isUsed = false;
};

struct rule {
    std::vector<sMath> tokens;
    std::string output;
    bool isOK = true;
};

bool checkMathSyntax(std::string);
std::vector<sMath> splitStringFormula(std::string);
std::vector<std::string> splitToTokens(std::string, char);
std::string addSpacesAroundOP(std::string, std::string);
bool isNumber(const std::string &s);
bool isOP(const std::string &s);
bool checkSemantics(std::vector<sMath>, std::vector<port *>);

#endif //TEST_ICPMATH_HPP

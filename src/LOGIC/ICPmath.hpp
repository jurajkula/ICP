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

/**
 * @brief The sMathTypes enum
 */
enum sMathTypes {
    sMathType_OP,
    sMathType_VAR,
    sMathType_CONST
};

/**
 * @brief The table enum
 */
enum table {
    TE,
    TL,
    TM,
    TX,
};

/**
 * @brief The sMath struct
 */
struct sMath {
    /**
     * @brief value
     */
    std::string value;

    /**
     * @brief type
     */
    int type;

    /**
     * @brief isUsed
     */
    bool isUsed = false;
};

/**
 * @brief The rule struct
 */
struct rule {
    /**
     * @brief tokens
     */
    std::vector<sMath> tokens;

    /**
     * @brief output
     */
    std::string output;

    /**
     * @brief isOK
     */
    bool isOK = true;
};


/**
 * @brief checkMathSyntax Function, which check if math schema is correct
 * @param s Math schema as string
 * @return Return TRUE, if schema si correct, else return FALSE
 */
bool checkMathSyntax(std::string s);

/**
 * @brief splitToTokens Support function, which input string split to tokens
 * @param str Input string
 * @param delimiter Delimiter, which split string
 * @return Return vector of strings => tokens
 */
std::vector<std::string> splitToTokens(std::string str, char delimiter);

/**
 * @brief addSpacesAroundOP Support function, which add space around operands
 * @param s Input string
 * @param op Operand
 * @return Return new string
 */
std::string addSpacesAroundOP(std::string s, std::string op);

/**
 * @brief isNumber Suport function, which checks if input is number
 * @param s Input string
 * @return Return TRUE, if string was number, else return FALSE
 */
bool isNumber(const std::string &s);

/**
 * @brief isOP Support function, which checks if input is operand
 * @param s Input string
 * @return Return TRUE, if string was operand, else return FALSE
 */
bool isOP(const std::string &s);

/**
 * @brief splitStringFormula Function, which input string splits to tokens, create math tokens and return vector of them
 * @param s Input string
 * @return Return created vector of math tokens
 */
std::vector<sMath> splitStringFormula(std::string s);

/**
 * @brief checkSemanticsOutput Funciton, which check semantic correction of output
 * @param ports Vector of ports
 * @param output Output of math schema
 * @return Return TRUE, if semantic is correct, else return FALSE
 */
bool checkSemanticsOutput(std::vector<port *> ports, std::string output);

/**
 * @brief checkSemantics Funciton, which check semantic correction
 * @param v Vector of math tokens
 * @param ports Vector of ports
 * @return Return TRUE, if semantic is correct, else return FALSE
 */
bool checkSemantics(std::vector<sMath> v, std::vector<port *> ports);

/**
 * @brief getOPid Support function, which return operand ID
 * @param s Input operand
 * @return Return operand ID
 */
int getOPid(std::string s);

/**
 * @brief convertStringToDouble Support function, wchich convert std::string to double
 * @param s Input string
 * @return Return double value
 */
double convertStringToDouble (std::string s);

/**
 * @brief computeAaddB Function, which adds 2 vars
 * @param a Var a
 * @param b Var b
 * @return Return output
 */
double computeAaddB(double a, double b);

/**
 * @brief computeAsubB Function, wchich subs 2 vars
 * @param a Var a
 * @param b Var b
 * @return Return output
 */
double computeAsubB(double a, double b);

/**
 * @brief computeAmulB Function, which muls 2 vars
 * @param a Var a
 * @param b Var b
 * @return Return output
 */
double computeAmulB(double a, double b);

/**
 * @brief computeAdivB Function, which div var A by var B
 * @param a Var a
 * @param b Var b
 * @return Return output
 */
double computeAdivB(double a, double b);

/**
 * @brief computeAopB Function, which calls compute functions based on operand
 * @param a Var a
 * @param op Operand
 * @param b Var b
 * @return Return output
 */
double computeAopB(double a, int op, double b);

/**
 * @brief runComputing Function, which start computing
 * @param r Rule - info
 * @param v Vector of tokens
 * @param ports Vector of ports
 * @return Return output
 */
double runComputing(rule *r, std::vector<sMath> v, std::vector<port *> ports);
#endif //TEST_ICPMATH_HPP

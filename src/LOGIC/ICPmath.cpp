//
// Created by jurajkula on 8.4.2018.
//


#include "ICPmath.hpp"

int exprTav [5][5] {
//           +    -  *   /   id
/* +  */    {TM, TM, TL, TL, TL},
/* -  */    {TM, TM, TL, TL, TL},
/* *  */    {TM, TM, TM, TM, TL},
/* /  */    {TM, TM, TM, TM, TL},
/* id */    {TM, TM, TM, TM, TX},
};

bool checkMathSyntax(std::string s) {
    std::regex e (R"((?:[\s]*(?:[a-zA-Z][a-zA-z0-9]*|[0]|[1-9][0-9]*|[0]\.[0-9]+|[1-9][0-9]*\.[0-9]+)[\s]*(?:\n|\+|\-|\*|\/)[\s]*)+)"); //regex kontrolujuci spravnost vzorca (syntax)
    std::regex op (R"(.*[\+\-\*\/][\s]*)"); // REGEX, ak je operand poslednym znakom
    if (std::regex_match(s, op)) {
        return false;
    }

    return std::regex_match(s, e);
}

std::vector<std::string> splitToTokens(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

std::string addSpacesAroundOP(std::string s, std::string es) {
    std::string pom;
    std::string replacator;
    replacator.append(" ");
    replacator.append(es);
    replacator.append(" ");

    std::regex e("\\"+es);
    std::regex_replace(std::back_inserter(pom), s.begin(), s.end(), e, replacator);

    return pom;
}

bool isNumber(const std::string &s) {
    if (!s.empty() && std::all_of(s.begin(), s.end(), ::isdigit))
        return true;

    char *endptr = nullptr;
    strtod(s.data(), &endptr);

    return !(*endptr != '\0' || endptr == s.data());

}

bool isOP(const std::string &s) {
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

std::vector<sMath> splitStringFormula(std::string s) {
    std::vector<sMath> formula;

    s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

    s = addSpacesAroundOP(s, "+");
    s = addSpacesAroundOP(s, "-");
    s = addSpacesAroundOP(s, "*");
    s = addSpacesAroundOP(s, "/");

    std::vector<std::string> tokens = splitToTokens(s, ' ');

    sMath m;
    for (const std::string &t : tokens) {
        m.value = t;

        if (isNumber(t))
            m.type = sMathType_CONST;
        else if (isOP(t))
            m.type = sMathType_OP;
        else
            m.type = sMathType_VAR;

        formula.push_back(m);
    }

    return formula;
}

bool checkSemantics(std::vector<sMath> v, std::vector<port *> ports) {
    for (const sMath &m : v) {
        for (port *p : ports) {
            if (p->findData(m.value))
                return true;
        }
    }
    return false;
}


int getOPid(std::string s) {
    if(s == "+")
        return 0;
    else if (s == "-")
        return 1;
    else if (s == "*")
        return 2;
    else
        return 3;
}

double convertStringToDouble (std::string s) {
    char * pEnd;
    return strtod(s.data(), &pEnd);

}

double computeAaddB(double a, double b) {
    return a + b;
}

double computeAsubB(double a, double b) {
    return a - b;
}

double computeAmulB(double a, double b) {
    return a * b;
}

double computeAdivB(double a, double b) {
    return a / b;
}

double computeAopB(double a, int op, double b) {
    switch (op) {
        case 0: return computeAaddB(a,b);
        case 1: return computeAsubB(a,b);
        case 2: return computeAmulB(a,b);
        default: return computeAdivB(a,b);
    }
}

// TODO ?????
double runComputing(rule *r, std::vector<sMath> v, std::vector<port *> ports) {
    std::vector<sMath> tokens = v;
    std::vector<double> stack;
    unsigned long stackC = 0;
    double output = 0;

    if (tokens.size() == 1) {
        if (tokens.back().type == sMathType_CONST) {
            output = convertStringToDouble(tokens.back().value);
        }
        else {
            for (port *p : ports) {
                if ((p->findData(tokens.back().value)) && (p->getStatus() == INPUT )) {
                    output = p->returnData(tokens.back().value).value;
                    break;
                }
            }
        }
        return output;
    }

    while(!tokens.empty()) {

        for (unsigned long i = 0; i < tokens.size(); i++) {
            if(tokens.at(i).type == sMathType_OP) {

                if ((tokens.size() <= i+2) || (exprTav[i][i+2] == TM)) {

                    double a,b,c;
                    if (tokens.at(i-1).isUsed) {
                        a = stack.at(stackC);
                        stackC++;
                    }
                    else {
                        a = convertStringToDouble(tokens.at(i-1).value);
                    }

                    if (tokens.at(i+1).isUsed) {
                        b = stack.at(stackC);
                        stackC++;
                    }
                    else {
                        b = convertStringToDouble(tokens.at(i+1).value);
                    }

                    c = computeAopB(a,getOPid(tokens.at(i).value),b);

                    if (std::isnan(c)) {
                        r->isOK = false;
                        return 0;
                    }

                    tokens.erase(tokens.begin() + i + 1);
                    tokens.erase(tokens.begin() + i);
                    tokens.at(i-1).isUsed = true;

                    if (stackC > 0) {
                        stack.erase(stack.begin() + stackC - 1);
                        if (stackC > 1) {
                            stack.erase(stack.begin() + stackC - 2);
                            stackC--;
                        }
                        stackC--;
                    }
                    stack.push_back(c);


                    break;
                }
            }
        }

        if (tokens.size() == 1) {
            if (tokens.back().isUsed) {
                return stack.at(0);
            }
            else {
                return convertStringToDouble(tokens.back().value);
            }
        }
    }
}
//
// Created by 18017 on 10/10/2022.
//

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H
#include "Token.h"
#include "lexer.h"
#include "DatalogProgram.h"

using namespace std;

class Parser {

private:


    vector<Token*>tokens;


public:
    Parser(vector<Token *> tokensFromMain);
    DatalogProgram parse(vector<Token *> tokens);
};


#endif //PROJECT_1_PARSER_H

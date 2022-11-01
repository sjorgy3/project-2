//
// Created by 18017 on 10/10/2022.
//

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H
#include "Token.h"
#include "lexer.h"
#include "DatalogProgram.h"
#include "Predicate.h"

using namespace std;

class Parser {

private:

    int tokenLocation =0;
    vector<Token*>tokens;
    DatalogProgram object;
    Predicate newPredicate;


public:

    Parser(vector<Token *> tokensFromMain);
    ~Parser();
    DatalogProgram datalogprogram();
    void parse();
    void schemeList();
    void factList();
    void ruleList();
    void queryList();
    void scheme();
    void fact();
    void rule();
    void query();
    void headPredicate();
    void predicate();
    void predicateList();
    void parameterList();
    void stringList();
    void idList();
    void parameter();

    void match(TokenType tokenType);
};


#endif //PROJECT_1_PARSER_H

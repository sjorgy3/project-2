//
// Created by 18017 on 10/10/2022.
//

#include <iostream>
#include "Parser.h"
#include "Token.h"
#include "lexer.h"
using namespace std;

Parser::Parser(vector<Token *> tokensFromMain) {
    tokens = tokensFromMain;
    parse();
}
Parser::~Parser()=default;


void Parser::match(TokenType tokenType){
    //TokenType type = tokens.at(tokenLocation)->getType();
    if(tokens.at(tokenLocation)->getType() == tokenType){
        tokenLocation++;
    }
    else{
        throw *tokens.at(tokenLocation);
    }

}

void Parser::parse() {
    try {
        datalogprogram();
        cout << "Success!" << endl;

    }
    catch (Token error){
        cout << "Failure!" << endl;
        cout << "  (" << tokens.at(tokenLocation)->tokenToSTring(tokens.at(tokenLocation)->getType()) << ",\""<<  tokens.at(tokenLocation)->getdescription()<<"\","<<tokens.at(tokenLocation)->getLine() << ")";

    }



}
DatalogProgram Parser::datalogprogram(){

    //datalogProgram	->	SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    match(TokenType::SCHEMES);
    match(TokenType::COLON);
    scheme();
    schemeList();
    match(TokenType::FACTS);
    match(TokenType::COLON);
    factList();
    match(TokenType::RULES);
    match(TokenType::COLON);
    ruleList();
    match(TokenType::QUERIES);
    match(TokenType::COLON);
    query();
    queryList();
    match(TokenType::ENDOFFILE);

}
//schemeList	->	scheme schemeList | lambda Follow = FACTS
void Parser::schemeList() {
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        scheme();
        schemeList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::FACTS){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
//factList	->	fact factList | lambda
void Parser::factList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        fact();
        factList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RULES){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::ruleList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        rule();
        ruleList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::QUERIES){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}

void Parser::queryList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::ID){
        query();
        queryList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::ENDOFFILE){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::scheme(){
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    idList();
    match(TokenType::RIGHT_PAREN);

}
void Parser::fact(){
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::STRING);
    stringList();
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);



}
void Parser::rule(){
    headPredicate();
    match(TokenType::COLON_DASH);
    predicate();
    predicateList();
    match(TokenType::PERIOD);

}
void Parser::query(){
    predicate();
    match(TokenType::Q_MARK);

}
void Parser::headPredicate(){
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    idList();
    match(TokenType::RIGHT_PAREN);







}
void Parser::predicate(){
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    parameter();
    parameterList();
    match(TokenType::RIGHT_PAREN);




}
void Parser::predicateList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        predicate();
        predicateList();

    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::PERIOD){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::parameterList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        parameter();
        parameterList();
    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RIGHT_PAREN){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::stringList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        match(TokenType::STRING);
        stringList();



    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RIGHT_PAREN){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::idList(){
    if (tokens.at(tokenLocation)->getType() == TokenType::COMMA){
        match(TokenType::COMMA);
        match(TokenType::ID);
        idList();


    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::RIGHT_PAREN){

    }

    else{
        throw *tokens.at(tokenLocation);
    }


}
void Parser::parameter(){
    if (tokens.at(tokenLocation)->getType() == TokenType::STRING){
        match(TokenType::STRING);


    }
    else if(tokens.at(tokenLocation)->getType() == TokenType::ID){
        match(TokenType::ID);
    }

    else{
        throw *tokens.at(tokenLocation);
    }
    

}






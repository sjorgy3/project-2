//
// Created by 18017 on 10/10/2022.
//

#include "DatalogProgram.h"
#include "Predicate.h"
void DatalogProgram::addToSchemes(Predicate newScheme) {
    schemes.push_back(newScheme);

}

void DatalogProgram::addToFacts(Predicate newFact) {
    facts.push_back(newFact);
}

void DatalogProgram::addToRules(Rule newRule) {
    rules.push_back(newRule);
}

void DatalogProgram::addToQueries(Predicate newQuery) {
    queries.push_back(newQuery);
}

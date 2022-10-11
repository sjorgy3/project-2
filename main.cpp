#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {

    ifstream infile(argv[1]);

    string text, line;
    while(getline(infile, line))
    {
        text += line + '\n';
    }

//
//    if (infile.is_open()){
//        stringstream str;
//        str << infile.rdbuf();
//        text = str.str();
//
//
//
//    }
    infile.close();



    Lexer* lexer = new Lexer();


    lexer->Run(text);


    delete lexer;

    return 0;
}
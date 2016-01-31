#include "lexer.hpp"
#include <iostream>

int main(){
    std::cout << "compiler 0.0.0 test lexer a" << "\n";
    Lexer lex("testi.txt");
    auto t = lex.nextToken();
    while(t.tok != Tok::END){
        std::cout << t << "\n";
        t = lex.nextToken();
    }
}

/**
* @Author: Oskari Mieskolainen <Oskuz>
* @Date:   2016-02-01T15:21:41+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   Oskuz
* @Last modified time: 2016-02-01T15:21:41+02:00
*/
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

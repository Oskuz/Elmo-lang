/**
* @Author: Oskari Mieskolainen <oskari>
* @Date:   2016-02-28T15:44:45+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016Mar27
*/



#ifndef PARSER_HPP
#define PARSER_HPP "0.0.0"
#include "lexer.hpp"
#include "node.hpp"
#include <string>

namespace parser {
        Node *module(Lexer* lex);
        Node *statement(Lexer* lex);
        Node *import(Lexer* lex);
        Node *type(Lexer* lex);
        Node *function(Lexer* lex);
        Node *function_call(Lexer* lex);
        Node *struct_(Lexer* lex);
        long interger(std::string s);
        float floatNumber(std::string s);
} /* parser */
#endif

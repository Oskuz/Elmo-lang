/**
* @Author: Oskari Mieskolainen <oskari>
* @Date:   2016-02-28T19:14:29+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016Mar25
*/



#include"parser.hpp"
#include "node.hpp"
#include "lexer.hpp"
#include <string>
#include <vector>

using namespace std;
/*
 Node* parser::module(Lexer* lex){
     auto t = lex->nextToken();
     if(t.tok != Tok.IDENTIFIER_KEY && t.value != "module"){
         return ParseError("wait keyword module, get: \'"+t.value+"\'",t.region);
     }
     t  = lex->nextToken();
     if(t.tok != Tok.IDENTIFIER_REGULAR ){
         return ParseError("wait module's name, get: \'"+t.value+"\'",t.region);
     }
     auto name = t.value;
     t = lex->getToken();
     if(t.tok != Tok::SPECIAL && t.value != "{") return ParseError("wait character \'{\', get: \'"+t.value+"\'",t.region);
     vector<Node*>statements;
     while (lex->peekToken().value != "}")
     {
         auto statement = parser::statement(lex);
         if (statement->type == NodeType::DECLARATION){
             statement->data.declaration->external = true;
         }
         if (statement->type == NodeType::PARSE_ERROR){
             return statement;
         }
         statements.push_back(statement);
     }
     lex->getToken() // }
     return Node(Module(n))

 }
*/

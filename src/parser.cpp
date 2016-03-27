/**
* @Author: Oskari Mieskolainen <oskari>
* @Date:   2016-02-28T19:14:29+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016Mar27
*/



#include"parser.hpp"
#include "node.hpp"
#include "lexer.hpp"
#include <string>
#include <vector>

using namespace std;

 Node* parser::module(Lexer* lex){
     auto t = lex->getToken();
     if(t.tok != Tok::IDENTIFIER_KEY && t.value != "module"){
         return new Node(new ParseError("wait keyword module, get: \'"+t.value+"\'",t.region));
     }
     t  = lex->getToken();
     if(t.tok != Tok::IDENTIFIER_REGULAR ){
         return new Node(new ParseError("wait module's name, get: \'"+t.value+"\'",t.region));
     }
     auto name = t.value;

     t = lex->peekToken();
        if (t.tok == Tok::IDENTIFIER_KEY && t.value == "import"){
            parser::import(lex);
        }
     t = lex->getToken();
     if(t.tok != Tok::SPECIAL && t.value != "{") return new Node( new ParseError("wait character \'{\', get: \'"+t.value+"\'",t.region));
     vector<Node*>statements;
     while (lex->peekToken().value != "}")
     {
         auto statement = parser::statement(lex);
         if (statement->type == NodeType::DECLARING){
            // statement.data->declaration->external = true;
         }
         if (statement->type == NodeType::PARSE_ERROR){
             return statement;
         }
         statements.push_back(statement);
     }
     lex->getToken(); // }
     return new Node( new Module{name, statements});
 }

 Node* parser::import(Lexer* lex){
     return new Node();
 }

 Node* parser::statement(Lexer* lex){

     auto t = lex->peekToken();
      //declare functions.. and other statements"(")"(")
        if(t.value == "("){
            auto tt = lex->peekToken();
            t = lex->peekToken();
            if(tt.type == Tok::IDENTIFIER_REGULAR && t.value == ":" ){
                //its new func
                return parser::function(lex);
            }
            lex->getToken(); //eat (
            return parser::function_call(lex);
        }
        //declare struct
        if(t.value == "{")
            return parser::struct_(lex);
        if(t.type == Tok::IDENTIFIER_REGULAR)
            return parser::function_call(lex);
        return new Node();
 }

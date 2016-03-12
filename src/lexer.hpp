/**
* @Author: Oskari Mieskolainen <Oskuz>
* @Date:   2016-02-01T15:21:37+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016-03-12T20:46:42+02:00
*/
#ifndef LEXER
#define LEXER  0

#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/include/lex_lexertl.hpp"

#include <string>

using namespace boost::spirit;
using namespace boost::spirit::ascii;

template <typename Lexer>
struct tokens: lex::lexer<Lexer>
    {
        tokens()
            {
                //patterns
                this->self.add_pattern("identifier","[^ \t\n{}\\.\"\'\\[\\],:[0-9]#@]+[^ \t\n{}\\.\"\'\\[\\],]:*");
                this->self.add_pattern("special","(\\(|\\)|[|]|,|\\.)");
                this->self.add_pattern("string", "\"(.)*\"");
                this->self.add_pattern("character", "\'(.)?\'");
                this->self.add_pattern("interger","(-)?[0-9]+([0-9]|_)*" );
                this->self.add_pattern("float", "(-)?[0-9]+\\.[0-9]+");
                this->self.add_pattern("comment", "((###(.|\n|\r)*###)|(#(.)*))");
                this->self.add_pattern("attribute", "@(^ \n\t)*");

                //tokens
                identifier = "{identifier}";
                special = "{special}";
                string = "{string}";
                character = "{character}";
                interger = "{interger}";
                float_ = "{float}";
                comment = "{comment}";
                attribute = "{attribute}";

                this->self.add
                            (identifier)
                            (special)
                            (string)
                            (character)
                            (interger)
                            (float_)
                            (comment)
                            (attribute)
                            ("\n")
                            ("{")
                            ("}")
                            (":")
                            (" ")
                            (".", IDANY)
                            ;
            }
            lex::token_def<std::string>identifier;
            lex::token_def<std::string>special;
            lex::token_def<std::string>string;
            lex::token_def<char>character;
            lex::token_def<std::string>interger;
            lex::token_def<std::string>float_;
            lex::token_def<std::string>comment;
            lex::token_def<std::string>attribute;
    };



#define START_LINE 1
#define START_COL 1
#endif

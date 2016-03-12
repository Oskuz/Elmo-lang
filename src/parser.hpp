/**
* @Author: Oskari Mieskolainen <oskari>
* @Date:   2016-02-28T15:44:45+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016-03-12T22:03:00+02:00
*/



#ifndef PARSER_HPP
#define PARSER_HPP "0.0.0"

#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/include/lex_lexertl.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_statement.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "node.hpp"
#include "lexer.hpp"
#include <string>

using namespace boost::spirit;
using namespace boost::spirit::ascii;
using namespace qi::labels;

template<typename Iterator>
struct gammar_count : qi::grammar<Iterator>
{
    template <typename TokenDef>
    grammar_count(TokenDef const &tok): grammar_count::base_type(start), c(0), l(0)
        {
            using boost::phoenix::ref;
            using boost::phoenix::size;
            parameter = (
                        tok.identifier [_val->data->name = _1]
                        >> (
                            (lit(":") >> tok.identifier) [_val->data->type = _1]
                            |(tok.identifier >> statement) [_val->data->initialValue = _2; ]
                           )
                        );
            struct_ = (lit("{")
                       >> *(parameter) [_val->data->values.push_back(_1)]
                       >>lit("}")
                       );
            function_call = (
                            statement >> tok.identifier >> statement [_val->data->argl.push_back(_1); _val->data->name = _2; _val->data->argr.push_back(_3)]
                            |statement >> tok.identifier [_val->data->argl.push_back(_1); _val->data->name = _2]
                            |tok.identifier >>  *(statement) [_val->data->name = _1; _val->data->argr.push_back(_2)]
                            );
            procedure = (
                            lit("{")
                            >> *(attribute|type|declaring|statement) [_val->data->statements.push_back(_1)]
                            >> lit("}")
                        );
            function = (
                        (
                            tok.special >> *parameter >> tok.special 
                            >> tok.special >>  *parameter >> tok.special
                            | tok.special >> *parameter >> tok.special
                        ) >> procedure
                       );
            string = ( tok.string );
            character = (tok.character);
            interger = (tok.interger);
            float_ = (tok.float_);
            statement = ( tok.identifier >> (struct_ | function_call | function | string | character | interger | float_ | statement) >> tok.identifier
                        | struct_ | function_call | function | string | character | interger | float_ | statement
                        );
            attribute = (tok.attribute);
            declaring = (tok.identifier >> -tok.identifier >> tok.identifier >> statement);
            type = (tok.identifier >> tok.identifier >> tok.identifier)
            module = tok.identifier >> tok.identifier >> procedure ;
            start = *(module);
        }
    qi::rule<Iterator> start;
    qi::rule<Iterator, Node(Structure())> struct_;
    qi::rule<Iterator, Node(Parameter())> parameter;
    qi::rule<Iterator, Node(Function_call())> function_call;
    qi::rule<Iterator> procedure;
    qi::rule<Iterator> function;
    qi::rule<Iterator> string;
    qi::rule<Iterator> character;
    qi::rule<Iterator> interger;
    qi::rule<Iterator> float_;
    qi::rule<Iterator> statement;
    qi::rule<Iterator> attribute;
    qi::rule<Iterator> declaring;
    qi::rule<Iterator> type;
    qi::rule<Iterator> module;
};
#endif

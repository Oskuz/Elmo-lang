#include "lexer.hpp"
#include <string>
#include <vector>
#include <ctype.h>
#include <cassert>
#include <unistd.h>
#include <iostream>

using namespace std;

//todo: isoperator, isnumber, isIdfStartC
bool Lexer::ispecial(string s){
    for (string var : specials)
    {
        if(var == s) return true;
    }
    return false;
}

bool Lexer::isoperator(std::string s){
    for (string var : operators)
    {
        if(var == s) return true;
    }
    return false;
}
bool Lexer::iskeyword(string s){
    for (std::string var : keywords)
    {
        if(var == s) return true;
    }
    return false;
}
bool Lexer::isnumber(char s){
    return isdigit(s);
}
bool Lexer::isIdfStartC(char s){
    return isalpha(s);
}
Token Lexer::nextToken(){
    //eof?
    if(context.length() == 0){
        return Token(Tok::END, "", Region(file,loc.line,loc.col,loc.col));
    }

    //whitespace, newline is token!
    if(context[0] == ' '){
        unsigned long ws = 0;
        while (context.size() > ws && context[ws] == ' '){
            ws++;
        }
        //std::cout << "space:"<<ws << "\n";
        eat(ws);
    }
    //newline
    if(context[0] == '\n'){
        Token tok = Token(Tok::NEWLINE,"\\n",Region(file,loc.line,loc.col,loc.col));
        loc.line++;
        eat(1);
        loc.col = 0;
        return tok;
    }
    //comment
    if(context.size() > 0 && context[0]=='#'){
        auto nl = 0;
        while(context[nl] == '\n'){
            nl++;
        }
        Token ret = Token(Tok::COMMENT, context.substr(0,(unsigned long)nl), Region(file,loc.line, loc.col, loc.col + nl));
        eat((unsigned long)nl);
    }
    //string
    if(context[0] == '\"' ){
        if(context.length() == 1){
            return Token(Tok::ERROR,"cannot end with '\"'", Region(file,loc.line,loc.col, loc.col + 1));
        }
        unsigned long lstri = 1;
        while(context.length() != lstri && context[lstri] != '\"'){
            lstri++;
        }
        Token ret = Token(Tok::STRING, context.substr(1, lstri - 1 ), Region(file, loc.line, loc.col, loc.col + lstri));
        eat(lstri + 1);
        return ret;
    }
    //character
    if(context[0] == '\'' ){
        if(context.length() == 1){
            return Token(Tok::ERROR,"cannot end with '\''", Region(file,loc.line,loc.col, loc.col + 1));
        }
        unsigned long lstri = 1;
        while(context.length() != lstri && context[lstri] != '\''){
            lstri++;
        }
        Token ret = Token(Tok::CHARACTER, context.substr(1, lstri - 1 ), Region(file, loc.line, loc.col, loc.col + lstri));
        eat(lstri + 1);
        return ret;
    }
    //numeric data
    if(isnumber(context[0])){
        auto i = 0;
        auto number = "";
        while(i < context.size() && (isnumber(context[i])
                                                        || context[i] =='.'
                                                        || context[i] == '_'
                                                        || context[i] == 'x'
                                                        || context[i] == 'b'
                                                        || context[i] == 'A'
                                                        || context[i] == 'B'
                                                        || context[i] == 'C'
                                                        || context[i] == 'D'
                                                        || context[i] == 'E'
                                                        || context[i] == 'F') )
            {
                if(context[i] != '_'){
                    number += context[i];
                }
                i += 1;
            }
            Token ret = Token(Tok::NUMBER, number, Region(file, loc.line, loc.col, loc.col + i));
            eat((unsigned long)i);
            return ret;
    }
    //operators
    if(isoperator(string(1,context[0]))){
        auto i = 0;
        while(i < context.size() && isoperator(string(1,context[i])))
            {
            i++;
            }
        auto ret = Token(Tok::OPERATOR,context.substr(0,i),Region(file, loc.line, loc.col, loc.col + i));
        eat((unsigned long)i);
        return ret;
    }
    //specials
    if (ispecial(string(1,context[0]))){
        auto ret = Token(Tok::SPECIAL,string(1,context[0]), Region(file, loc.line, loc.col, loc.col));
        eat(1);
        return ret;
    }
    // identifiers
    if(isIdfStartC(context[0])){
        unsigned long i = 0;
        while(i < context.size() && (context[i] != ' '&& context[i] != '\n') && !isoperator(string(1,context[i])) && !ispecial(string(1,context[i])))
        {
            i++;
        }
        auto s = context.substr(0,i);
        Token ret;
        if(iskeyword(s)){
            ret = Token(Tok::IDENTIFIER_KEY, s, Region(file, loc.line, loc.col, loc.col + i));
        }
        else{
            ret = Token(Tok::IDENTIFIER_REGULAR, s, Region(file, loc.line, loc.col, loc.col + i));
        }
        eat(i);
        return ret;
    }
    auto ret = Token(Tok::ERROR, string("unexpected token " + context[0]), Region(file,
                                                                               loc.line,
                                                                               loc.col,
                                                                               loc.col + 1));
   eat(1);
   return ret;
}

void Lexer::eat(unsigned long length)
{
    assert(length <= context.size());
    //cout<<"lenght "<<length<<"\n";
    context = context.substr( length, context.size());
    loc.col += length;
    //std::cout <<"col "<< loc.col << "\n";
}

string readFile(string file){
    if(file.length() > 0 && file[0] != '/'){
        char current[FILENAME_MAX];
        file = string(getcwd(current, sizeof(current))) +'/'+ file;
    }
    ifstream afile (file);
    if(afile.is_open()){
      string content(istreambuf_iterator<char>(afile), (istreambuf_iterator<char>()));
      std::cout << content << "\n";
      return content;
    }
    else{
        std::cout << "unable open file " <<file <<"\n";
    }
}

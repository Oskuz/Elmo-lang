/**
* @Author: Oskari Mieskolainen <Oskuz>
* @Date:   2016-02-01T15:21:37+02:00
* @Email:  oskuz@outlook.com
* @Last modified by:   oskari
* @Last modified time: 2016-02-28T19:14:40+02:00
*/
#ifndef LEXER
#define LEXER  0
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

#define START_LINE 1
#define START_COL 1

using namespace std;
string readFile(string file);

struct Location {
    unsigned long line;
    unsigned long col;

    Location(): line(START_LINE), col(START_COL){}
    Location(unsigned long line_, unsigned long col_){
        line = line_;
        col = col_;
    }
    std::ostream& print(std::ostream& os) const{
        //std::cout << col << "\n";
        return os << line <<":"<< (unsigned long)col;
    }
};
inline std::ostream& operator<<(std::ostream& os, Location const &loc) {
    return loc.print(os);
}

struct Region {
    string fileName;
    Location start;
    Location end;

    Region(): start(Location()), end(Location()){}
    Region(string fileName, unsigned long line, unsigned long start_col, unsigned long end_col):
        fileName(fileName), start(Location(line,start_col)), end(Location(line,end_col)){}
    Region(Location start, Location end): start(start), end(end){fileName = "-";}

    std::ostream& print(std::ostream &os) const{
         os << "region in "<<fileName<<" from "<<start<<" to "<<end;
         return os;
    }

};
inline std::ostream& operator<<(std::ostream &os, Region const &reg){
    return reg.print(os);
}

enum Tok {CHARACTER, COMMENT,ERROR, END, IDENTIFIER_KEY, IDENTIFIER_REGULAR, NEWLINE, NONE, NUMBER, OPERATOR, SPECIAL, STRING};
enum OpType {};

vector<string> const specials = {"{",
                                "}",
                                 "(",
                                ")",
                                 ";",
                                 ","
                             };
vector<string> const operators = {
                                "+",
                                "-",
                                "/",
                                "*",
                                "^",
                                "¨",
                                "~",
                                "!",
                                "=",
                                ".",
                                "\\",
                                "%",
                                "¤",
                                "&",
                                "?",
                                "<",
                                ">",
                                "|",
                                ":"

                            };
vector<string> const keywords = {
                            "import",
                            "module",
                            "let",
                            "type",
                            "impl",
                            "for",
                            "in",
                            "ret",
                            "rec",
                            "if",
                            "else",


};
struct Token
{
    Tok tok;
    string value;
    Region region;

    Token() : tok(Tok::NONE), value(""), region(Region()) { }
    Token(Tok _tok, string _value, Region _region) : tok(_tok), value(_value), region(_region) { }
    std::ostream &print(std::ostream &os) const {
         os << "token "<<tok<<" value: "<<value<<" in "<<region;
         return os;
    }
};
inline std::ostream &operator<<(std::ostream &os, const Token &tok){
    return tok.print(os);
}

struct Lexer{
    string file;
    string context;
    Location loc;
    std::stack<Token> buffer;

    Lexer(string file_): file(file_) {
        context = readFile(file);
        loc = Location();
    }
    Token nextToken();
    Token peekToken(){
        auto t = nextToken();
        buffer.push(t);
        return t;
    }
    Token getToken(){
        if(buffer.size() > 0){
            auto t = buffer.top(); buffer.pop(); return t;
        }
        return nextToken();
    }
    void eat(unsigned long lenght);
    bool ispecial(string s);
    bool isoperator(string s);
    bool isnumber(char s);
    bool isIdfStartC(char s);
    bool iskeyword(string s);
};
#endif

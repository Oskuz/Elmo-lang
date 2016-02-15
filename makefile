# @Author: Oskari Mieskolainen <Oskuz>
# @Date:   2016-02-15T11:36:43+02:00
# @Email:  oskuz@outlook.com
# @Last modified by:   Oskuz
# @Last modified time: 2016-02-15T11:40:15+02:00



compiler : main.o lexer.o
	g++ -std=c++11 -o compiler main.o lexer.o
main.o : main.cpp lexer.hpp node.hpp
	g++ -std=c++11 -c main.cpp
lexer.o : lexer.cpp lexer.hpp
	g++ -std=c++11 -c lexer.cpp

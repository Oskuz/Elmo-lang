compiler : main.o lexer.o
	g++ -std=c++11 -o compiler main.o lexer.o
main.o : main.cpp lexer.hpp
	g++ -std=c++11 -c main.cpp
lexer.o : lexer.cpp lexer.hpp
	g++ -std=c++11 -c lexer.cpp

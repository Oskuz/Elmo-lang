# @Author: Oskari Mieskolainen <Oskuz>
# @Date:   2016-02-15T11:36:43+02:00
# @Email:  oskuz@outlook.com
# @Last modified by:   oskari
# @Last modified time: 2016Mar25



compiler : main.o lexer.o node.o parser.o
	g++ -std=c++11 -I/src/boost -lspirit -o compiler main.o lexer.o parser.o
main.o : src/main.cpp src/lexer.hpp src/node.hpp
	g++ -std=c++11 -c src/main.cpp
lexer.o : src/lexer.cpp src/lexer.hpp
	g++ -std=c++11 -I src/boost -c src/lexer.cpp
node.o : src/node.hpp src/node.cpp
	g++ -std=c++11 -c src/node.cpp
parser.o : src/parser.hpp
	g++ -I src/boost

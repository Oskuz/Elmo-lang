# @Author: Oskari Mieskolainen <Oskuz>
# @Date:   2016-02-15T11:36:43+02:00
# @Email:  oskuz@outlook.com
# @Last modified by:   Oskuz
# @Last modified time: 2016-02-15T11:49:47+02:00



compiler : main.o lexer.o node.o
	g++ -std=c++11 -o compiler main.o lexer.o
main.o : src/main.cpp src/lexer.hpp src/node.hpp
	g++ -std=c++11 -c src/main.cpp
lexer.o : src/lexer.cpp src/lexer.hpp
	g++ -std=c++11 -c src/lexer.cpp
node.o : src/node.hpp src/node.cpp
	g++ -std=c++11 -c src/node.cpp

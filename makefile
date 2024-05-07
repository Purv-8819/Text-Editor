build: main.cpp
	g++ -O2 -Wall -I. -g -std=c++2a main.cpp -o main

run: main
	./main

build_test: test.cpp
	g++ -O2 -Wall -I. -g -std=c++2a -I/opt/homebrew/Cellar/googletest/1.14.0/include -L/opt/homebrew/Cellar/googletest/1.14.0/lib test.cpp -lgtest -lgtest_main -lpthread -o test

run_test: test
	./test
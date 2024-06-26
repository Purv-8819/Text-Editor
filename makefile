build: main.cpp rope.cpp
	g++ -std=c++14 -O2 -Wall -I. -g -std=c++2a Node.cpp Rope.cpp main.cpp -o main.out

run:
	./main.out

build_test: test.cpp rope.cpp
	g++ -std=c++11 -O2 -Wall -I. -g -std=c++2a -I/opt/homebrew/Cellar/googletest/1.14.0/include -L/opt/homebrew/Cellar/googletest/1.14.0/lib Rope.cpp test.cpp -lgtest -lgtest_main -lpthread -o test.out

run_test: build_test
	./test.out
build: main.cpp rope.cpp
	g++ -O2 -Wall -I. -g -std=c++2a rope.cpp main.cpp -o main.out

run:
	./main.out

build_test: test.cpp rope.cpp
	g++ -O2 -Wall -I. -g -std=c++2a -I/opt/homebrew/Cellar/googletest/1.14.0/include -L/opt/homebrew/Cellar/googletest/1.14.0/lib rope.cpp test.cpp -lgtest -lgtest_main -lpthread -o test.out

run_test: build_test
	./test.out
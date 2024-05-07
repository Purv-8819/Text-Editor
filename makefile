build: main.cpp
	g++ -O2 -Wall -I. -g -std=c++2a main.cpp -o main

run: main
	./main
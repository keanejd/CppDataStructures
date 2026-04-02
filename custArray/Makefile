CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -MMD -MP
ANIMAL_DIR = ../animal

all: test 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -I$(ANIMAL_DIR) -c main.cpp

test: main.o
	$(CXX) $(CXXFLAGS) -o test main.o -L$(ANIMAL_DIR) -lanimal
	./test > custArray_results.txt

clean:
	rm -f *.o *.d test

.PHONY: all test clean
-include $(wildcard *.d)
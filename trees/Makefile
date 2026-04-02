CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -MMD -MP
ANIMAL_DIR = ../animal

all: test

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -I$(ANIMAL_DIR) -c main.cpp

test: main.o
	$(CXX) $(CXXFLAGS) -o test main.o -L$(ANIMAL_DIR) -lanimal
	./test 

debug: CXXFLAGS += -g -fsanitize=address,undefined
debug: main.o
	$(CXX) $(CXXFLAGS) -o test_debug main.o -L$(ANIMAL_DIR) -lanimal

clean:
	rm -f *.o *.d test test_debug

.PHONY: all test clean debug 

-include $(wildcard *.d)
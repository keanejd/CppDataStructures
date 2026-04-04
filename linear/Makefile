CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I../animal -MMD -MP

all: test

test: main.o
	$(CXX) $(CXXFLAGS) -o test main.o -L../animal -lanimal
	./test > linear_results.txt

debug: CXXFLAGS += -g -fsanitize=address,undefined
debug: main.o
	$(CXX) $(CXXFLAGS) -o test_debug main.o -L../animal -lanimal

clean:
	rm -f *.o *.d test test_debug

.PHONY: all test clean debug

-include $(wildcard *.d)
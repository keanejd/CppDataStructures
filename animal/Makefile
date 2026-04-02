CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -MMD -MP

all: libanimal.a

Animal.o: Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp

AnimalTest.o: AnimalTest.cpp AnimalTest.h
	$(CXX) $(CXXFLAGS) -c AnimalTest.cpp

libanimal.a: Animal.o AnimalTest.o
	ar rcs libanimal.a Animal.o AnimalTest.o

clean:
	rm -f *.o *.d *.a

.PHONY: all clean
-include $(wildcard *.d)
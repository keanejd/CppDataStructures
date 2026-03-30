CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: libanimal.a

Animal.o AnimalTest.o: Animal.cpp Animal.h AnimalTest.cpp AnimalTest.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp AnimalTest.cpp

libanimal.a: Animal.o AnimalTest.o
	ar rcs libanimal.a Animal.o AnimalTest.o

clean:
	rm -f *.o *.a

.PHONY: all clean
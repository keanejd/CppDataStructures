#include "AnimalTest.h"
#include <fstream>
#include <stdexcept>
// constructors
AnimalTest::AnimalTest(){
    nameCount = 0;
    typeCount = 0;
    size = 0;
    zoo = nullptr;
    animalNames = readText("../animal/names.txt", nameCount);
    animalTypes = readText("../animal/animals.txt", typeCount);
}
AnimalTest::AnimalTest(std::string _fileName1, std::string _fileName2) {
    nameCount = 0;
    typeCount = 0;
    size = 0;
    zoo = nullptr;
    animalNames = readText(_fileName1, nameCount);
    animalTypes = readText(_fileName2, typeCount);

}
//destructor
AnimalTest::~AnimalTest() {
    delete[] animalNames;
    delete[] animalTypes;
    delete[] zoo;
}

//getter functions
int AnimalTest::getSize() const {return size;}
Animal* AnimalTest::getZoo() const {return zoo;}

std::string* AnimalTest::readText(const std::string& _fileName, int& _count) {
    std::ifstream file(_fileName);
    if(!file.is_open()) {
        std::cout<<"Error! File not found: " << _fileName <<std::endl;
        return nullptr;

    }

    std::string line;
    while(std::getline(file, line)) _count++;

    file.clear();
    file.seekg(0);
    std::string* arr = new std::string[_count];
    for(int i = 0; i < _count; i++) std::getline(file, arr[i]);

    file.close();
    return arr;

}

int AnimalTest::randomNumber(int _min, int _max) {
    return (rand() % (_max - _min + 1)) + _min;
}

std::string AnimalTest::chooseName() {
    return animalNames[randomNumber(0, nameCount - 1)];
}

std::string AnimalTest::chooseType() {
    return animalTypes[randomNumber(0, typeCount - 1)];
}

void AnimalTest::fillZoo(int _numAnimals, int _minAge, int _maxAge) {
    delete[] zoo;
    zoo = new Animal[_numAnimals];
    size = _numAnimals;
    for(int i = 0; i < _numAnimals; i++)
        zoo[i] = Animal(chooseName(), randomNumber(_minAge, _maxAge), chooseType());
}





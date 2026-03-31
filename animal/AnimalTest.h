#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class AnimalTest {

private:
    static constexpr int PRIORITY_RANGE = 1000000;
    std::string* animalNames;
    std::string* animalTypes;
    int nameCount;
    int typeCount;
    int size;

public:
    Animal * zoo;

    AnimalTest();
    AnimalTest(std::string _fileName1, std::string _fileName2);
    ~AnimalTest();

    int getSize() const;
    Animal* getZoo() const;

    std::string* readText(const std::string& _fileName, int& _count);
    int randomNumber(int _min, int _max);
    std::string chooseName();
    std::string chooseType();
    void fillZoo(int _numAnimals, int _minAge, int _maxAge);
};

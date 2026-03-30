#include "Animal.h"

Animal::Animal() : name("Unkown"), age(0), type("Uknown") {}

Animal::Animal(std::string _name, int _age, std::string _type)
    : name(_name), age(_age), type(_type) {}

Animal::Animal(const Animal& _other)
    : Animal(_other.name, _other.age, _other.type) {}

Animal& Animal::operator=(const Animal& _other) {
    if(this != &_other) {
        name = _other.name;
        age = _other.age;
        type = _other.type;
    }
        return *this;
}

//getters
std::string Animal::getName() const {return name;}
int Animal::getAge() const { return age; }
std::string Animal::getType() const { return type; }

//setters
void Animal::setName(std::string _name) { name = _name; }
void Animal::setAge(int _age) { age = _age;}
void Animal::setType(std::string _type) {type = _type;}

bool Animal::operator==(const Animal& _other) const {
    return type == _other.type;
}

bool Animal::operator<(const Animal& _other) const {
    return type < _other.type;
}

bool Animal::operator>(const Animal& _other) const {
    return type > _other.type;
}

std::ostream& operator<<(std::ostream& os, const Animal& _animal){
    os << "Animal name: " << _animal.name
        <<" Animal age: " << _animal.age
        <<" Animal type: "<< _animal.type;
    return os;
}



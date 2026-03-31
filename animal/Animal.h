#pragma once
#include <string>
#include <iostream>

class Animal {

protected:
    std::string name;
    int age;
    std::string type;
    int priority;

public:
    Animal();
    Animal(std::string _name, int _age, std::string _type, int priority );
    Animal(const Animal& _other);
    Animal& operator=(const Animal& _other);

    std::string getName() const;
    int getAge() const;
    std::string getType() const;
    int getPriority() const; 

    void setName(std::string _name);
    void setAge(int _age);
    void setType(std::string _type);
    void setPriority(int _priority); 

    bool operator==(const Animal& _other) const;
    bool operator<(const Animal& _other) const;
    bool operator>(const Animal& _other) const;
    friend std::ostream& operator<<(std::ostream& os, const Animal& _animal);

};

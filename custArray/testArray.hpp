#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "custArray.hpp"
#include "Animal.h"
#include "AnimalTest.h"

AnimalTest * filltheZoo(int _numAnimals, int _minAge, int _maxAge){
    AnimalTest* theZoo = new AnimalTest();
    theZoo->fillZoo(_numAnimals, _minAge, _maxAge);

    return theZoo;
}

template<typename T>
void FillArray(custArray<T>&  _c, T * _array, int _size ) {

    std::cout<<"We are filling the Array with this many elements: " <<_size <<"\n";
    for(int i = 0; i < _size; i++){
        _c.addElement(_array[i]);
    }
}

template<typename T>
void printArray(custArray<T>&  _c) {
    std::cout<<"\n";
    std::cout<<"The array size is " << _c.getSize() << " The tail pointer is at " << _c.getTail()<<"\n";
    _c.printArray();
    std::cout<<"\n";
}

template<typename T>
void printArray(custArray<T>& _c, T * _array, int _size) {
    std::cout<<"\n";
    std::cout<<"The array size is " << _c.getSize() << " The tail pointer is at " << _c.getTail()<<"OVERLOADED\n";
    _c.printArray(_array, _size);
    std::cout<<"\n";
}

template<typename T>
void swapTest(custArray<T>& _c, int _a, int _b) {
    std::cout<<"-----------------Testing the swap function----------------------\n";
    std::cout<<"Before the swap\n";
    printArray(_c);
    _c.swapElements(_a, _b);
    std::cout<<"After the swap\n";
    printArray(_c);
}

template<typename T>
void removeTest(custArray<T>& _c, int _a ) {

    T temp = _c.removeElement(_a);
     std::cout<<"-----------------Testing the remove function----------------------\n";
     std::cout<<"\n";
     std::cout<<"The removed element is: "<< temp << "\n";
     printArray(_c);

}

template<typename T >
void  addElementTest(custArray<T>& _c, T * _array, int _a, int _size) {
    std::cout<<"-----------------Testing the add function----------------------\n";

    for(int i = 0; i < _a; i++) {
        _c.addElement(_array[rand() % _size]);
    }

    printArray(_c);

}
template<typename T>
void addDuplicates(custArray<T>& _c,  T * _array, int _a, int _size) {
      std::cout<<"-----------------Testing the add duplicates function----------------------\n";
    for(int i = 0; i < _a; i++) {
        _c.addElement( _array[rand() % _size] );
    }
    printArray(_c);

}

template<typename T>
void removeDuplicates(custArray<T>& _c, const T& _data) {
      std::cout<<"-----------------Testing the remove all duplicates function----------------------\n";
    _c.removeAll(_data);

    printArray(_c);
}

template<typename T>
void findDuplicates(custArray<T>& _c, const T& _data) {
   std::cout<<"-----------------Testing the add duplicates function----------------------\n";
   std::cout<<"=================Finding Duplicates of the First Element==================\n";
    int size;
    int * duplicates = _c.indexDuplicates(_data, size);

    for(int i = 0; i < size; i++) {
        std::cout<<"The " << i << " duplicate is " << _c.peek( duplicates[i] )<<"\n";
    }

    T temp = _c.getElement(duplicates[0]); 
    std::cout<<"=================Removing Duplicates of the First Element==================\n";
    removeDuplicates(_c, temp);
    delete []  duplicates;

}


/* public static <T> void sortArray(const custArray<T>& _c) {
    std::cout<<("------------------Sorting the Array----------------------");
    std::cout<<("=================Sorting the animals by AGE ==================");
    _c.sort();
    printArray(_c);

}
*/
void testFunctions() {

    AnimalTest * test = filltheZoo(15, 1, 50);
    
    custArray<Animal> * animalArr = new custArray<Animal>(test->getSize()/2);

    FillArray(*animalArr, test->zoo, test->getSize()/2);
    printArray(*animalArr);

    printArray(*animalArr, test->zoo, test->getSize());

    swapTest(*animalArr, 0, 6);    

    removeTest(*animalArr, 0);

    addDuplicates(*animalArr, test->zoo, test->getSize(), test->getSize() );

    findDuplicates(*animalArr, animalArr->getElement(0) );

    //sortArray(animalArr);

    delete test;
    delete animalArr;

}





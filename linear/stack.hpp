#pragma once
#include <iostream>
#include <utility>
#include "doubleList.hpp"

template <typename  T>

class stack {
    private:
    
        doubleList<T>* list;
    
    public:

        stack() : list( new doubleList<T>() ) {}
        ~stack() {delete list;}

        stack(const stack& _other) : list(new doubleList<T>(*_other.list)) {}

        stack<T>& operator=( const stack<T>& _other) {
            if(this != &_other ){
                queue<T> temp(_other);
                std::swap(this->list, temp.list);
            }
            return *this;
        }



        int getSize(){return list->getSize();}

        bool isEmpty(){ return getSize() == 0 ;}

        T peek() { 
            if( isEmpty() ) {
                std::cout << "The stack is Empty";
                return T();
            }    
            
            return list->peekRear();
        }

        T pop() { 
            if( isEmpty() ) {
                std::cout<<" The queue is Empty";
                return T();
            }
        
            return list->removeRear();
        }

        void push(const T& _data) {
            list->addRear(_data);
        }

        void printStack() {
            std::cout<<"This is a stack of size "<< getSize() <<"\n";
            list->printReverse();
            std::cout<<"\n";
        }
};
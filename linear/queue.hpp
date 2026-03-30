#pragma once
#include <iostream>
#include <utility>
#include "doubleList.hpp"

template <typename  T>

class queue {
    private:
    
        doubleList<T>* list;
    
    public:

        queue() : list( new doubleList<T>() ) {}
        ~queue() {delete list;}

        queue(const queue& _other) : list(new doubleList<T>(*_other.list)) {}

        queue<T>& operator=( const queue<T>& _other) {
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
                std::cout << "The queue is Empty";
                return T();
            }    
            
            return list->peekFront();
        }

        T poll() { 
            if( isEmpty() ) {
                std::cout<<" The queue is Empty";
                return T();
            }
        
            return list->removeFront();
        }

        void offer(const T& _data) {
            list->addRear(_data);
        }

        void printQueue() {
            std::cout<<"This is a queue of size "<< getSize() <<"\n";
            list->printList();
            std::cout<<"\n";
        }
};
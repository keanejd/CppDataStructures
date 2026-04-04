#pragma once
#include <iostream>
#include <utility>
#include "doubleNode.hpp"
#include "itDL.hpp"

template <typename T>
class doubleList {

    private:
        doubleNode<T>* head;
        doubleNode<T>* tail;
        int size;

        itDL<T> begin()  { return itDL<T>(this->head); }
        itDL<T> end()    { return itDL<T>(nullptr); }
        itDL<T> rbegin() { return itDL<T>(this->tail); }
        itDL<T> rend()   { return itDL<T>(nullptr); }

        T remove(doubleNode<T> * _node) {
            if(_node->getPrev() == nullptr) return removeFront();
            if(_node->getNext() == nullptr) return removeRear();

            T data = _node->getData();

            _node->getNext()->setPrev(_node->getPrev());
            _node->getPrev()->setNext(_node->getNext());

            delete _node;
            size--;

            return data;
        }


    public: 
        doubleList() : head(nullptr), tail(nullptr), size(0){}
        
        ~doubleList() { clear();}

        doubleList(const doubleList<T>&  _other) : head(nullptr), tail(nullptr), size(0) {
            doubleNode<T>* current = _other.head;
            while(current != nullptr) {
                this->addRear(current->getData());
                current = current->getNext();
            } 
        }

        doubleList<T>& operator =(const doubleList<T>& _other) {
            if(this != &_other) {
                doubleList<T> temp(_other);
                std::swap(head , temp.head);
                std::swap(tail , temp.tail);
                std::swap(size , temp.size);
            }
            return *this;
        }

        doubleNode<T>* getHead() { return head;}
        doubleNode<T>* getTail() { return tail;}
        int getSize() const {return size;}
        bool isEmpty() const { return head == nullptr && tail == nullptr;}

        void clear() {
            doubleNode<T>*  current = head;
            while(current != nullptr){
                doubleNode<T>* temp = current->getNext();
                delete current;
                current = temp;
            }
            head = tail = nullptr;
            size = 0;
        }

        void addFront(const T& _data) {
            doubleNode<T>* temp = new doubleNode<T>(_data);
            if( isEmpty() )
                head = tail = temp;
            else {
                head->setPrev(temp);
                temp->setNext(head);
                head = temp;
            }
            size++;
        }

        void addRear(const T& _data) {
            doubleNode<T>* temp = new doubleNode<T>(_data);
            if( isEmpty() ) 
                tail = head = temp;
            else{
                tail->setNext(temp);
                temp->setPrev(tail);
                tail = temp;
            }
            size++;
        }

        void add(const T& _data) {
            addFront(_data);
        }

        T removeFront(){
            if( isEmpty() ) return T();

            T data = head->getData();
            doubleNode<T>* temp  = head;
            head = head->getNext();
            
            if( head != nullptr) head->setPrevNull();
            else
                tail = nullptr;

            delete temp;
            size--;
            return data;
        }

        T removeRear() {
            if(isEmpty() ) return T();

            T data = tail->getData();
            doubleNode<T>* temp = tail;
            tail = tail->getPrev();

            if(tail != nullptr) tail->setNextNull();
            else    
                head = nullptr;

            delete temp;
            size--;
            return data;
        }

        T peekFront()const{
            if( isEmpty() ) return T();
            return head->getData();
        }

        T peekRear() const {
            if( isEmpty() ) return T();
            return tail->getData();
        }

        T removeAtIndex (int _index) {
            if(_index >= size || _index < 0 ) {
                std::cout<<"Check your _index value \n";
                return T();
            }
            doubleNode<T>* temp;
            int i;
    
            if( _index >  (size/2) ){
                for(i = size-1, temp = tail; _index != i; i-- )
                    temp = temp->getPrev();
            }
            else{
                for(i = 0 , temp = head; _index != i; i++)
                    temp = temp->getNext();
            }
            return remove(temp);
        }
      
        bool ifRemoved(const T& _data) {
            doubleNode<T>* temp;

             for( temp = head ; temp != nullptr; temp = temp->getNext()) {
                if( temp->getData() == _data ){
                    remove(temp);
                    return true;
                } 
            }
            return false;
        }

        int indexOf (const T& _data){
            
            doubleNode<T>* temp;
            int index = 0;
            
            for(temp = head; temp != nullptr; index++){
                if( temp->getData() == _data )
                    return index;
                temp = temp->getNext();
            }      
            return -1;
        }

        bool inList( const T& _data) {
            return indexOf(_data) != -1;
        }

        void printList() {
            int i = 0;
            for( auto it = begin(); it != end(); ++it)
                    std::cout<< i++ << ". " << *it << " DL-->\n";
            std::cout<<"The end of the DoubleList of size  "<<size<<"\n\n";
        }
  
  
        void printReverse(){
            int i = 0; 
            for(auto it = rbegin(); it != rend(); --it)
                    std::cout<< i++ << ". " << *it << " DL-->\n";
            std::cout<<"The end of the DoubleList of size " << size <<"\n\n";
        }        
};
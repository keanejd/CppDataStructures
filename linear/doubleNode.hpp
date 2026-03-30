#pragma once
#include <iostream>

template <typename T>
class doubleNode {
    private:
        T data;
        doubleNode<T>* next;
        doubleNode<T>* prev;
    
    public:
        doubleNode() : data(T()), next(nullptr), prev(nullptr) {}
        doubleNode(const T& _data) : data(_data), next(nullptr), prev(nullptr) {}
        ~doubleNode() = default;

        doubleNode(const doubleNode<T>& _other) : data(_other.data), next(nullptr), prev(nullptr) {}

        doubleNode<T>& operator =(const doubleNode<T>& _other) {
            if(this != &_other)
                data = _other.data;
            return * this;
        }

        T getData() { return data;}
        doubleNode<T>* getNext() {return next;}
        doubleNode<T>* getPrev() {return prev;}

        void setData(const T& _data) { data = _data;}
        void setNext(doubleNode<T>* _next) {next = _next;}
        void setPrev(doubleNode<T>* _prev) { prev = _prev;}
        void setNextNull() { next = nullptr;}
        void setPrevNull() { prev = nullptr;}

        void print() { std::cout<< data;}
};
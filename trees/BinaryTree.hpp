#pragma once 
#include "BinaryNode.hpp"

template<typename T>
class BinaryTree {
  public:
    virtual ~BinaryTree() = default;

    virtual bool insert(const T & _data) = 0;
    virtual bool remove(const T & _data) = 0;
    virtual bool contains(const T & _data) = 0;
    virtual int height() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual int  printHeight() = 0;
    virtual BinaryNode<T> * getRoot() const = 0;
};

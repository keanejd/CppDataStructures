#pragma once
#include "TreeNode.hpp"

template <typename T>
class AVLNode {
    private:
        int height;
        int balanceFactor;
        AVLNode<T> * left;
        AVLNode<T> * right;
        T data;
          
public:
    AVLNode(const T& _data) : data(_data), left(nullptr), right(nullptr), height(0), balanceFactor(0) {}
    AVLNode() : AVLNode(T()) {}

    ~AVLNode() = default;
    AVLNode(const AVLNode<T>& _other) : AVLNode(_other.data) {}

    AVLNode<T> & operator=(const AVLNode<T> & _other) {
        if(this != &_other){
             data = _other.data;
        }
    
     return * this;
    }
    
    bool operator ==(const AVLNode<T>& _other) const {
        return  getData() == _other.getData(); 
    }      
    
    bool operator >(const AVLNode<T>& _other) const {
        return  getData() > _other.getData(); 
    }
    
    bool operator <(const AVLNode<T>& _other) const {
        return  getData() < _other.getData(); 
    }

    //getters
    const T&  getData() const {return data;}
    AVLNode<T>  * getLeft()const{ return left;}
    AVLNode<T>  * getRight() const { return right;}
    int getHeight() const { return height;}
    int getBalanceFactor(){ return balanceFactor;}

    //setters
    void setData(const T& _data) { data = _data;}
    void setLeft(AVLNode<T> * _left) { left = _left;}
    void setRight(AVLNode<T> * _right) {right = _right;}
    void setHeight(int _height) { height = _height;}
    void setBalanceFactor(int _balanceFactor) { balanceFactor = _balanceFactor;}
    void setRightNull() { right = nullptr;}
    void setLeftNull() { left = nullptr; }

    friend std::ostream& operator<<(std::ostream& os, const AVLNode<T>& _node) {
        os << _node.data;
        return os;
    }
};


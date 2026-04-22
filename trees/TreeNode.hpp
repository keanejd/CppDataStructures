#pragma once
#include<iostream>
#include"BinaryNode.hpp"
template <typename T>
class TreeNode : public  BinaryNode<T> {

private:
    T data;
    TreeNode<T> * left;
    TreeNode<T> * right;

public:
    TreeNode() : data(T()) , left(nullptr), right(nullptr) {}

    TreeNode(const T& _data) : data(_data), left(nullptr), right(nullptr) {}

    ~TreeNode() = default;
    TreeNode(const TreeNode<T>& _other) : TreeNode(_other.data) {}

    TreeNode<T>& operator=(const TreeNode<T>& _other) {
        if(this != &_other){
             data = _other.data;
        }
    
     return * this;
    }
    
    bool operator ==(const TreeNode<T>& _other) const {
        return  getData() == _other.getData(); 
    }      
    
    bool operator >(const TreeNode<T>& _other) const {
        return  getData() > _other.getData(); 
    }
    
    bool operator <(const TreeNode<T>& _other) const {
        return  getData() < _other.getData(); 
    }

    //getters
    const T&  getData() const override {return data;}
    TreeNode<T> * getLeft() const override { return left;}
    TreeNode<T> * getRight() const override { return right;}

    //setters
    void setData(const T& _data) { data = _data;}
    void setLeft(TreeNode<T> * _left) { left = _left;}
    void setRight(TreeNode<T> * _right) {right = _right;}
    void setRightNull() { right = nullptr;}
    void setLeftNull() { left = nullptr; }


    friend std::ostream& operator<<(std::ostream& os, const TreeNode<T>& _node) {
        os << _node.data;
        return os;
    }
};

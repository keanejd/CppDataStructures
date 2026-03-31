#pragma once
#include<iostream>

template <typename T>
class TreeNode {

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
        if(this != _other){
             data = _other.data;
        }
     return * this;
    }

    //getters
    T  getData() const {return data;}
    TreeNode<T> * getLeft()const{ return left;}
    TreeNode<T> * getRight() const { return right;}

    //setters
    void setData(const T& _data) { data = _data;}
    void setLeft(TreeNode<T> * _left) { left = _left;}
    void setRight(TreeNode<T> * _right) {right = _right;}
    void setRightNull() { right = nullptr;}
    void setLeftNull() { left = nullptr; }


};
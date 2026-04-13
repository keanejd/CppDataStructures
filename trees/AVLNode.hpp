#pragma once
#include "TreeNode.hpp"

template <typename T>
class AVLNode : public TreeNode<T> {
    private:
        int height;
        int balanceFactor;
    
    public:
        AVLNode(const T& _data) : TreeNode<T>(_data), height(0), balanceFactor(0) {}
        AVLNode() : AVLNode(T()) {}
        ~AVLNode() = default;

        AVLNode(const AVLNode<T>& _other) {
            TreeNode<T>(_other), height(__other.height), balanceFactor(_other.balanceFactor) {}

        }

        AVLNode<T>& operator=(const AVLNode<T>& _other){
            TreeNode<T>::operator=(_other);
            height = _other.height;
            balanceFactor = _other.balanceFactor;
            return *this;
        }

        int getHeight() const {return height;}
        int getBalanceFactor() const { return balanceFactor;}

        void setHeight(int _height)  { height = _height;}
        void setBalanceFactor(int _bf) {balanceFactor = _bf;}
        
};


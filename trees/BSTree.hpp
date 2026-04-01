#pragma once
#include<iostream>
#include<algorithm>
#include "TreeNode.hpp"

template <typename T>
class BSTree {
    private:
        TreeNode<T> * root;
        int nodeCount;

        // pass the root --> to this function for adding
        TreeNode<T> * add(TreeNode<T>* _node, const T& _data) {
            if(_node == nullptr)
                return new TreeNode<T>(_data);
            if( _data < _node->getData())
                _node->setLeft(add(_node->getLeft(), _data));
            else
                _node->setRight(add(_node->getRight(), _data));
           
            return _node;
        }

        bool contains(TreeNode<T>* _node, const T& _data) {
            
            if(_node == nullptr) return false;
            
            if( _data == _node->getData() ) return true;
            
            if( _data < _node->getData() ) 
                    return contains(_node->getLeft(), _data);
            else
                return contains(_node->getRight(), _data);
        }

        TreeNode<T> * findMin(TreeNode<T> *  _node) {
            while(_node->getLeft() != nullptr) _node = _node->getLeft();
                return _node;
        }

        TreeNode<T> * findMax(TreeNode<T> * _node) {
            while (_node->getRight() != nullptr) _node = _node->getRight();
                return _node;
        }     
        
        int height(TreeNode<T> * _node) {
            if (_node == nullptr) return 0;

            return std::max(height( _node->getLeft() ), height(_node->getRight() )) + 1;
        }

        TreeNode<T> * remove(TreeNode<T> * _node, T _data) {
            if( _node == nullptr) return nullptr;

            //left subtree
            if( _node->getData() > _data)
                _node->setLeft( remove(_node->getLeft(), _data) );
            //right subtree    
            
            else if(_node->getData() < _data)
                _node->setRight( remove(_node->getRight(), _data) );
            else {
                if(_node->getLeft()  == nullptr) {
                    TreeNode<T> * rightChild = _node->getRight();
                    delete _node;
                    return rightChild;    
                }
                else if( _node->getRight() == nullptr ) {
                    TreeNode<T> * leftChild = _node->getLeft();
                    delete _node;
                    return leftChild;
                }

                else {
                    // leftmost node in the right subtree
                    TreeNode<T> * temp = findMin( _node->getRight() ) ;
                    _node->setData(temp->getData());
                    _node->setRight( remove(temp->getRight(), temp->getData()));
                }
            }
            return _node;
        }


    public:
        BSTree() : root(nullptr), nodeCount(0) {}
        BSTree(const T& _data) {
            root = new TreeNode(_data);
            nodeCount++;
        } 
        
        bool addNode(const T& _data) {
            if( contains(root, _data) )
                return false;
            else {
                root = add(root, _data);
                nodeCount++;
                return true;
            }
        }

        bool removeNode(const T& _data) {
            if( contains(_data) ){
                nodeCount--;
                root = remove(root, _data);
                return true;
            }
            else    
                return false;
        }
        
        bool conatainsData(const T& _data) {
            return contains(root, _data);
        }

        int treeHeight() {
            return height(root);
        }


        
};
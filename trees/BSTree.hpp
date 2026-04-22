#pragma once
#include<iostream>
#include<algorithm>
#include "TreeNode.hpp"
#include "BinaryTree.hpp"
#include "../linear/stack.hpp"
#include "../linear/queue.hpp"

template<typename T>
class BSTree : public BinaryTree<T> {
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
                    _node->setRight( remove(_node->getRight(), temp->getData()));
                }
            }
            return _node;
        }

        // private section, alongside add/remove/contains/etc.
        void destroy(TreeNode<T>* _node) {
            if (_node == nullptr) return;
            destroy(_node->getLeft());
             destroy(_node->getRight());
            delete _node;
        }

        TreeNode<T>* copyTree(TreeNode<T>* _node) {
            if (_node == nullptr) return nullptr;
                TreeNode<T>* newNode = new TreeNode<T>(*_node);
                newNode->setLeft(copyTree(_node->getLeft()));
                newNode->setRight(copyTree(_node->getRight()));
                return newNode;
        }

  public:
      BSTree() : root(nullptr), nodeCount(0) {}
      BSTree(const T& _data) {
          root = new TreeNode<T>(_data);
            nodeCount++;
        } 

        ~BSTree() {
           destroy(this->root);
           this->root = nullptr;
        }

       BSTree(const BSTree<T>& _other) : nodeCount(_other.nodeCount) {
          this->root = copyTree(_other.root);
        }

       BSTree<T>& operator=(const BSTree<T>& _other) {
          if (this == &_other) return *this;
          destroy(this->root);
           this->root = copyTree(_other.root);
          this->nodeCount = _other.nodeCount;
           return *this;
        }

        BinaryNode<T> * getRoot() const override {return root;}

        int size() override { return nodeCount;}

        bool isEmpty() override { return nodeCount == 0;}
        
        bool insert(const T& _data) override  {
            if( contains(root, _data) )
                return false;
            else {
                root = add(root, _data);
                nodeCount++;
                return true;
            }
        }

        bool remove(const T& _data) override {
            if( contains(root, _data) ){
                nodeCount--;
                root = remove(root, _data);
                return true;
            }
            else    
                return false;
        }
        
        bool contains(const T& _data) override {
            return contains(root, _data);
        }

        int height() override {
            return height(root);
        }

        enum class traversalType { PREORDER, INORDER, POSTORDER, LEVELORDER};

        class iterator {
            private: 
                traversalType travType;
                stack<TreeNode<T>*> nodeStack;
                stack<TreeNode<T>*>nodeStack2;
                queue<TreeNode<T>*> nodeQueue;

                void advancePreOrder() {
                    TreeNode<T>* node = nodeStack.pop();
                    if(node->getRight() != nullptr) 
                        nodeStack.push(node->getRight());
                    if(node->getLeft() != nullptr)
                        nodeStack.push(node->getLeft());
                }

                void advanceInOrder(){
                    TreeNode<T>* node = nodeStack.pop();
                    node = node->getRight();
                    while(node != nullptr) {
                        nodeStack.push(node);
                        node = node->getLeft();
                    }
                }

                void advancePostOrder() {
                    nodeStack2.pop();
                }

                void advanceLevelOrder() {
                    TreeNode<T>* node = nodeQueue.poll();
                    if(node->getRight() != nullptr) 
                        nodeQueue.offer(node->getRight());
                    if(node->getLeft() != nullptr)
                        nodeQueue.offer(node->getLeft());
                }

                public:
                    iterator(TreeNode<T>* _root, traversalType _type) : travType(_type) {
                        if(_root == nullptr) return;
                
                        else if(_type == traversalType::LEVELORDER)
                                nodeQueue.offer(_root);
                        
                        else if(_type == traversalType::INORDER) {
                            TreeNode<T>* node = _root;
                            while(node != nullptr) {
                                nodeStack.push(node);
                                node = node->getLeft();
                            }
                          }
                        else if(_type == traversalType::POSTORDER){
                              nodeStack.push(_root);
                              while(!nodeStack.isEmpty()){
                                    TreeNode<T>* node = nodeStack.pop();
                                    nodeStack2.push(node);
                                    if (node->getLeft() != nullptr) nodeStack.push(node->getLeft());
                                    if (node->getRight() != nullptr) nodeStack.push(node->getRight());
                              }
                        }
                        else 
                            nodeStack.push(_root);
                    }
                    
                
                    bool operator !=(const iterator& _other) const {
                        if(travType == traversalType::LEVELORDER)
                            return !nodeQueue.isEmpty();
                        if(travType == traversalType::POSTORDER)
                            return !nodeStack2.isEmpty();
                        return !nodeStack.isEmpty();
                    }

                    iterator& operator++() {
                        switch (travType) {
                            case traversalType::PREORDER: advancePreOrder(); break;
                            case traversalType::INORDER: advanceInOrder(); break;
                            case traversalType::POSTORDER: advancePostOrder(); break;
                            case traversalType::LEVELORDER: advanceLevelOrder(); break;
                        }
                        return * this;
                    }

                     const T& operator*() const {
                         if (travType == traversalType::LEVELORDER)
                             return nodeQueue.peek()->getData();
                         if (travType == traversalType::POSTORDER)
                            return nodeStack2.peek()->getData();
                        return nodeStack.peek()->getData();
                    }

                };

                iterator begin(traversalType _type) { return iterator(root, _type); }
                iterator end(traversalType _type) { return iterator(nullptr, _type); }
};

#pragma once 
#include "AVLNode.hpp"
#include "BinaryTree.hpp"

template<typename T>
class AVLTree : public BinaryTree<T> {
  private: 
    AVLNode<T> * root;
    int nodeCount;

    void destroy(AVLNode<T> * _node) {
      if(_node == nullptr) return;
        destroy(_node->getLeft());
        destroy(_node->getRight());
      delete _node;
    }

    AVLNode<T>* copyTree(AVLNode<T> * _node) {
      if(_node == nullptr) return nullptr;
        AVLNode<T>* newNode = new AVLNode<T>(*_node);
        newNode->setLeft(copyTree(_node->getLeft()));
        newNode->setRight(copyTree(_node->getRight()));
      return newNode;
    }

    bool contains(AVLNode<T> * _node, const T & _data) {
      if( _node == nullptr ) return false;

      else if(_node->getData() > _data) return contains(_node->getLeft(), _data);
      
      else if(_node->getData() < _data) return contains(_node->getRight(), _data);

      else 
          return true;
    }
  
    AVLNode<T> * insert(AVLNode<T> * _node, const T & _data){
      if(_node == nullptr) return new AVLNode<T>(_data);
      
      else if(_node->getData() > _data)  
          _node->setLeft(insert(_node->getLeft(), _data));
      
      else //(_node->getData() < _data) 
          _node->setRight(insert(_node->getRight(), _data));

      update(_node);

      return balance(_node);
      
    }

     void update(AVLNode<T> * _node) {
      int leftNodeHeight = (_node->getLeft() == nullptr) ? -1: _node->getLeft()->getHeight();
      int rightNodeHeight = (_node->getRight() == nullptr) ? -1: _node->getRight()->getHeight();

      _node->setHeight(1+std::max(leftNodeHeight,rightNodeHeight));

      _node->setBalanceFactor(rightNodeHeight-leftNodeHeight);

    }
    
     AVLNode<T> * balance(AVLNode<T> * _node ) {
       if(_node->getBalanceFactor() == -2){
         // left heavy subtree 
         if(_node->getLeft()->getBalanceFactor() <= 0)//left-left case 
            return leftLeftCase(_node);
         else //  left -right case
            return leftRightCase(_node);
         
       }
       // right heavy subtree 
       else if(_node->getBalanceFactor() == 2) {
         if(_node->getRight()->getBalanceFactor() >= 0)//right-right case
            return rightRightCase(_node);
         else // right-left case 
            return rightLeftCase(_node);
       } 

       return _node; //balance factor is 1, 0 , -1 
     }

     AVLNode<T> * leftLeftCase(AVLNode<T> * _node) {
       return rightRotation(_node);
     } 

     AVLNode<T> * leftRightCase(AVLNode<T> * _node) {
       _node->setLeft(leftRotation(_node->getLeft()));
       return leftLeftCase(_node);
     }

     AVLNode<T> * rightRightCase(AVLNode<T> * _node) {
       return leftRotation(_node);
     }

     AVLNode<T> * rightLeftCase(AVLNode<T> * _node){
       _node->setRight(rightRotation(_node->getRight()));
       return rightRightCase(_node);
     }

     AVLNode<T> * leftRotation(AVLNode<T> * _node) {
        AVLNode<T> * newParent = _node->getRight();
        _node->setRight(newParent->getLeft());
        newParent->setLeft(_node);
        update(_node);
        update(newParent);
        return newParent;
     }

     AVLNode<T> * rightRotation(AVLNode<T> * _node) {
        AVLNode<T> * newParent = _node->getLeft();
        _node->setLeft(newParent->getRight());
        newParent->setRight(_node);
        update(_node);
        update(newParent);
        return newParent;
     }

     AVLNode<T> * remove(AVLNode<T> * _node, T _data) {
            if( _node == nullptr) return nullptr;

            //left subtree
            if( _node->getData() > _data)
                _node->setLeft( remove(_node->getLeft(), _data) );
            //right subtree    
            
            else if(_node->getData() < _data)
                _node->setRight( remove(_node->getRight(), _data) );
            else {
                if(_node->getLeft()  == nullptr) {
                    AVLNode<T> * rightChild = _node->getRight();
                    delete _node;
                    return rightChild;    
                }
                else if( _node->getRight() == nullptr ) {
                    AVLNode<T> * leftChild = _node->getLeft();
                    delete _node;
                    return leftChild;
                }

                else {
                    // leftmost node in the right subtree
                    AVLNode<T> * temp = findMin( _node->getRight() ) ;
                    _node->setData(temp->getData());
                    _node->setRight( remove(_node->getRight(), temp->getData()));
                }
            }

            update(_node);
            return balance(_node);
      }

     AVLNode<T> * findMin(AVLNode<T> *  _node) {
            while(_node->getLeft() != nullptr) _node = _node->getLeft();
                return _node;
     }

     AVLNode<T> * findMax(AVLNode<T> * _node) {
            while (_node->getRight() != nullptr) _node = _node->getRight();
                return _node;
     }     




    public:
    AVLTree() : root(nullptr), nodeCount(0) {}
    AVLTree(const T& _data) {
      root = new AVLNode<T>(_data);
      nodeCount++;
    }

    ~AVLTree() {
      destroy(this->root);
      this->root = nullptr;
    }

    AVLTree(const AVLTree<T>& _other) : nodeCount(_other.nodeCount) {
      this->root = copyTree(_other.root);
    }

    AVLTree<T>& operator=(const AVLTree<T> & _other) {
      if(this == &_other) return *this;
        destroy(this->root);
        this->root = copyTree(_other.root);
        this->nodeCount = _other.nodeCount;
        return * this;
    }

    BinaryNode<T> * getRoot() const override { return root; }

    int height() override { 
      if(root == nullptr) return 0;
      
      return root->getHeight();
    }

    int size() override {
      return nodeCount;
    }

    bool isEmpty() override {
      return size() == 0;
    }

    bool contains(const T & _data) override {
      return contains(root, _data);
    }

    bool insert(const T & _data) override {
      if(!contains(root, _data) ) {
          root = insert(root, _data);
          nodeCount++;
          return true;
      }
      return false;
    }

    bool remove(const T & _data) override {
      if(contains(root, _data)){
        root = remove(root, _data);
        nodeCount--;
        return true;
      }
      return false;
    }




};

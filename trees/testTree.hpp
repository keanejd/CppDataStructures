#pragma once
#include "../linear/linearTest.hpp"
#include "BSTree.hpp"
#include "AVLTree.hpp"
#include "TreeTraversal.hpp"
#include <cmath>
#include <vector>
#include<string>
#include<bits/stdc++.h>

using std::vector;
using std::string;
using std::to_string;



template<typename T>
void treeHeight(BinaryTree<T>& _bst) {
    std::cout<<"The height of the Tree is: "<<_bst.height()<<"\n\n";
    std::cout<<"The tree has : "<< _bst.size()<<" nodes"<<std::endl;
    std::cout<<"Log2 of node count: "<<log2(_bst.size())<<"\n\n";
}

template<typename T>
void fillTree(T * _a, int _size, BinaryTree<T>& _bst){
    for(int i = 0; i < _size; i++)
        _bst.insert(_a[i]);
    treeHeight(_bst);
}

template<typename T>
void removeData(BinaryTree<T>& _bst, const T& _data){
    std::cout<<"Does the tree contain: "<<std::boolalpha 
    <<_bst.contains(_data)<<"\n\n";

    std::cout<<"Was the node removed: "<<std::boolalpha<<
     _bst.remove(_data)<< "\n\n";
     treeHeight(_bst);
}

template<typename T>
void preOrder(BinaryTree<T>& _bst) {

    std::cout<<"----------Testing the pre order traversal---------------"<<std::endl;
 
     TreeTraversal<T> explorer(&_bst);
     vector<T> result = explorer.traversePreOrder();
     for(auto & i : result) {
        std::cout<< i <<std::endl;
     }

    treeHeight(_bst);
}

template<typename T>
void postOrder(BinaryTree<T>& _bst) {
    std::cout<<"----------Testing the post order traversal---------------"<<std::endl;
   
     TreeTraversal<T> explorer(& _bst);
     vector<T> result = explorer.traversePostOrder();
     for(auto & i : result) {
        std::cout<< i <<std::endl;
     }

    treeHeight(_bst);

}

template<typename T>
void inOrder(BinaryTree<T>& _bst) {
    std::cout<<"----------Testing the in order traversal---------------"<<std::endl;
    
    TreeTraversal<T> explorer(& _bst);
     vector<T> result = explorer.traverseInOrder();
     for(auto & i : result) {
        std::cout<< i <<std::endl;
     }
    treeHeight(_bst);
}

template<typename T>
void levelOrder(BinaryTree<T>& _bst) {
    std::cout<<"----------Testing the level order traversal---------------"<<std::endl;

     TreeTraversal<T> explorer(& _bst);
     vector<T> result = explorer.traverseLevelOrder();
     for(auto & i : result) {
        std::cout<< i <<std::endl;
     }

    treeHeight(_bst);
}

template<typename T>
void printTree(BinaryTree<T>& _bst) {
    unsigned int h = _bst.printHeight();
    unsigned int width = (1 << h) - 1; // 2^h - 1
    std::cout<<"-----------Printing a Tree-------------------------------------"<<std::endl;    
    treeHeight(_bst);
    vector<vector<string>> matrix(h, vector<string>(width, " ")); // 7 spaces
    
    // recursive fill
    fillMatrix(matrix, _bst.getRoot(), 0, 0, width - 1);
    
    // print
    for (auto& row : matrix) {
        for (auto& cell : row)
            std::cout << cell;
        std::cout << "\n";
    }
}

template<typename T>
void fillMatrix( vector<vector<string>>& _matrix, BinaryNode<T>* _node, int _row, int _left, int _right) {
    if (_node == nullptr) return;
    
    int mid = (_left + _right) / 2;
    _matrix[_row][mid] = to_string(_node->getData());
    
    fillMatrix(_matrix, _node->getLeft(),  _row + 1, _left, mid - 1);
    fillMatrix(_matrix, _node->getRight(), _row + 1, mid + 1, _right);
}

template<typename T>
void testCopy( BinaryTree<T>& _orig,  BinaryTree<T>& _copy) {
  _copy = _orig;
  std::cout<<"Copying the trees ___________-------___________--------->"<<std::endl;

}
void testTree() {
    AnimalTest * test = fillThezoo(100, 1, 50);
    queue<Animal>* testQueue = new queue<Animal>();


    fillQueue(test->zoo, (test->getSize()/10 + 1),*testQueue);
   // stack<Animal>* testStack = new stack<Animal>();


    BSTree<Animal> * tree = new BSTree<Animal>();
    BSTree<int> * intTree = new BSTree<int>();
    BSTree<int> copyTree;
    AVLTree<int> * avlTree1 = new AVLTree<int>();



    testCopy(copyTree, *intTree);

    for(int i = 0; i < test->getSize()/5; i++) {
        intTree->insert(test->randomNumber(1,100));
        avlTree1->insert(test->randomNumber(1,100));
    }


    fillTree(test->zoo, (test->getSize()/10+1) , *tree);

   // treeHeight(*tree);

    removeData(*tree, testQueue->poll());

   // treeHeight(*tree);

    preOrder(*tree);
    postOrder(*tree);
    inOrder(*tree);
    levelOrder(*tree);
    printQueue(*testQueue);
    printTree(*intTree);
    copyTree = *intTree;
    printTree(copyTree);
    preOrder(*intTree);
    printTree(*avlTree1);
    preOrder(*avlTree1);
    postOrder(*avlTree1);
    inOrder(*avlTree1);
    levelOrder(*avlTree1);
    
    delete avlTree1;
    delete test;
    delete testQueue;
    delete tree;
    delete intTree;
};

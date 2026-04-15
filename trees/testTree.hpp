#pragma once
#include "../linear/linearTest.hpp"
#include "BSTree.hpp" 
#include <cmath>
#include <vector>
#include<string>

using std::vector;
using std::string;
using std::to_string;



template<typename T>
void treeHeight(BSTree<T>& _bst) {
    std::cout<<"The height of the Tree is: "<<_bst.treeHeight()<<"\n\n";
    std::cout<<"The tree has : "<< _bst.getSize()<<" nodes"<<std::endl;
    std::cout<<"Log2 of node count: "<<log2(_bst.getSize())<<"\n\n";
}

template<typename T>
void fillTree(T * _a, int _size, BSTree<T>& _bst){
    for(int i = 0; i < _size; i++)
        _bst.addNode(_a[i]);
    treeHeight(_bst);
}

template<typename T>
void removeData(BSTree<T>& _bst, const T& _data){
    std::cout<<"Does the tree contain: "<<std::boolalpha 
    <<_bst.conatainsData(_data)<<"\n\n";

    std::cout<<"Was the node removed: "<<std::boolalpha<<
     _bst.removeNode(_data)<< "\n\n";
     treeHeight(_bst);
}

template<typename T>
void preOrder(BSTree<T>& _bst) {

    std::cout<<"----------Testing the pre order traversal---------------"<<std::endl;
    for (auto it = _bst.begin(BSTree<T>::traversalType::PREORDER); it != _bst.end(BSTree<T>::traversalType::PREORDER); ++it) {
        std::cout << *it << std::endl;
    }
    treeHeight(_bst);
}

template<typename T>
void postOrder(BSTree<T>& _bst) {
    std::cout<<"----------Testing the post order traversal---------------"<<std::endl;
    for (auto it = _bst.begin(BSTree<T>::traversalType::POSTORDER); it != _bst.end(BSTree<T>::traversalType::PREORDER); ++it) {
        std::cout << *it << std::endl;
    }
    treeHeight(_bst);

}

template<typename T>
void inOrder(BSTree<T>& _bst) {
    std::cout<<"----------Testing the in order traversal---------------"<<std::endl;
    for (auto it = _bst.begin(BSTree<T>::traversalType::INORDER); it != _bst.end(BSTree<T>::traversalType::PREORDER); ++it) {
        std::cout << *it << std::endl;
    }

    treeHeight(_bst);
}

template<typename T>
void levelOrder(BSTree<T>& _bst) {
    std::cout<<"----------Testing the level order traversal---------------"<<std::endl;
    for (auto it = _bst.begin(BSTree<T>::traversalType::LEVELORDER); it != _bst.end(BSTree<T>::traversalType::PREORDER); ++it) {
        std::cout << *it << std::endl;
    }
    treeHeight(_bst);
}

template<typename T>
void printTree(BSTree<T>& _bst) {
    unsigned int h = _bst.treeHeight();
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
void fillMatrix( vector<vector<string>>& _matrix, TreeNode<T>* _node, int _row, int _left, int _right) {
    if (_node == nullptr) return;
    
    int mid = (_left + _right) / 2;
    _matrix[_row][mid] = to_string(_node->getData());
    
    fillMatrix(_matrix, _node->getLeft(),  _row + 1, _left, mid - 1);
    fillMatrix(_matrix, _node->getRight(), _row + 1, mid + 1, _right);
}
void testTree() {
    AnimalTest * test = fillThezoo(100, 1, 50);
    queue<Animal>* testQueue = new queue<Animal>();


    fillQueue(test->zoo, (test->getSize()/10 + 1),*testQueue);
   // stack<Animal>* testStack = new stack<Animal>();


    BSTree<Animal> * tree = new BSTree<Animal>();
    BSTree<int> * intTree = new BSTree<int>();
    BSTree<int> * copyTree = new BSTree<int>();

    for(int i = 0; i < test->getSize()/10; i++) {
        intTree->addNode(test->randomNumber(0,100));
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
    copyTree = intTree;
    printTree(*copyTree);
    
    delete test;
    delete testQueue;
    delete tree;
    delete intTree;
};

#pragma once
#include "../linear/linearTest.hpp"
#include "BSTree.hpp" 
#include <cmath>

template<typename T>
void fillTree(T * _a, int _size, BSTree<T>& _bst){
    for(int i = 0; i < _size; i++)
        _bst.addNode(_a[i]);
}

template<typename T>
void treeHeight(BSTree<T>& _bst) {
    std::cout<<"The height of the Tree is: "<<_bst.treeHeight()<<"\n\n";
    std::cout<<"The tree has : "<< _bst.getSize()<<" nodes\n";
    std::cout<<"Log2 of node count: "<<log2(_bst.getSize())<<"\n\n";
}

template<typename T>
void removeData(BSTree<T>& _bst, const T& _data){
    std::cout<<"Does the tree contain: "<<std::boolalpha 
    <<_bst.conatainsData(_data)<<"\n\n";

    std::cout<<"Was the node removed: "<<std::boolalpha<<
     _bst.removeNode(_data)<< "\n\n";
}

void testTree() {
    AnimalTest * test = fillThezoo(100, 1, 50);
    queue<Animal>* testQueue = new queue<Animal>();


    fillQueue(test->zoo, test->getSize(),*testQueue);
    stack<Animal>* testStack = new stack<Animal>();

   // printQueue(*testQueue);

    BSTree<Animal> * tree = new BSTree<Animal>();

    fillTree(test->zoo, test->getSize() , *tree);

    treeHeight(*tree);

    removeData(*tree, testQueue->poll());

    treeHeight(*tree);
}
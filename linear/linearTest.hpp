#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "doubleList.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "Animal.h"
#include "AnimalTest.h" 

 
 
 
 
 
AnimalTest * fillThezoo(int _numAnimals, int _minAge, int _maxAge){

    AnimalTest * theZoo = new AnimalTest();

    theZoo->fillZoo(_numAnimals, _minAge, _maxAge);

    return theZoo;
}

template <typename T>
void fillQueue(T * _a , int _size, queue<T>& _q )  {
        for( int  i = 0; i < _size ; i++)
            _q.offer(_a[i]);

}
template<typename T> 
void fillStack(T * _a, int _size,  stack<T>& _s)  {
        for( int  i = 0; i < _size ; i++)
            _s.push(_a[i]);

}

template<typename T>   
void fillList(T * _a, int _size,  doubleList<T>& _d)  {
        for( int  i = 0; i < _size ; i++)
            _d.add(_a[i]);
}

template<typename T>
void printStack(stack<T>& _s) {
        
       std::cout<<"------------This is the Stack----------------------\n";
       std::cout<<"The Stack size is "<<_s.getSize()<<"\n" ;
       std::cout<<"\n";
        _s.printStack();
       std::cout<<"\n";    
}

template<typename T>
void printList(doubleList<T>& _d) {
        
       std::cout<<"------------This is the List----------------------\n";
       std::cout<<"The List size is "<< _d.getSize()<<"\n" ;
       std::cout<<"\n";
        _d.printList();
       std::cout<<"\n";    
}

template<typename T>
void printQueue(queue<T>& _q) {
        
    std::cout<<"------------This is the Que----------------------\n";
    std::cout<<"The Queue size is "<<_q.getSize()<<"\n";
    std::cout<<"\n";
    _q.printQueue();
    std::cout<<"\n";
    
}

template<typename T>
void testPeek(stack<T>&  _s, queue<T>& _q ){

    std::cout<<"At the top of the Stack we have----------> "<< _s.peek()<<"\n";

    std::cout<<"At the front of the Queue we have--------> "<<_q.peek()<<"\n";
}

template<typename T>
void testPollPop(stack<T>& _s,  queue<T>& _q ){
    T temp1 = _s.pop();
    T temp2 = _q.poll();

    std::cout<<"We popped this value off the Stack----------------> "<<temp1<<"\n";
    std::cout<<"We got this value from the front of the Queue ----> "<<temp2<<"\n";

    std::cout<<"Putting the value--------> "<<temp1 <<"--------------> into the Queue \n ";
    _q.offer(temp1);
    std::cout<<"We are pushing ------> "<<temp2<<"---------> onto the Stack \n ";
    _s.push(temp2);

    printStack(_s);
    printQueue(_q);
}

template<typename T>
void testLookup(doubleList<T>& _l, stack<T>& _s) {
       
    T temp = _s.pop();
    std::cout<<"Finding the index of: "<< temp <<"\n";
    std::cout<<"The index is "<<_l.indexOf(temp)<< "\n";
    printList(_l);
    std::cout<<"Removing ---> "<<temp<<"\n";
    std::cout<<"Was the value removed: "<<_l.ifRemoved(temp)<<"\n";
    std::cout<<"Check is "<< temp <<" in the list now:"<<_l.inList(temp)<<"\n";
    printList(_l);
    std::cout<<"Remvoing the value at index 4 "<<_l.removeAtIndex(4)<<"\n";
    printList(_l);
}



    
void TestLinear() {

        AnimalTest * q = fillThezoo(10, 1, 50);

        AnimalTest * s = fillThezoo(10, 1, 50);

        queue<Animal>* testQueue = new queue<Animal>();
        stack<Animal>* testStack = new stack<Animal>();
        doubleList<Animal>* testList = new doubleList<Animal>();
    

        fillQueue(q->zoo, q->getSize(),*testQueue);
        fillStack(s->zoo, s->getSize(),*testStack);

        printQueue(*testQueue);

        printStack(*testStack);

        testPeek(*testStack, *testQueue);

        testPollPop(*testStack, *testQueue);
        fillList(s->zoo, s->getSize(), *testList );
        fillList(q->zoo, s->getSize(), *testList );
       
        printList(*testList);
        testLookup(*testList, *testStack);

        delete q;
        delete s;
        delete testQueue;
        delete testStack;
        delete testList;


}

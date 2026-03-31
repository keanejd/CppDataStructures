#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class custArray {

private:
        int size;
        int tailPtr;
        T* temp;
        T* array;

    void mergeSort( int _left, int _right){
        if(_left >= _right) return;

        int mid = (_left + _right) / 2;

        mergeSort(_left, mid);
        mergeSort(mid+1, _right);
        merge(_left, mid, _right);
    }

    void merge( int _left, int _mid, int _right) {
        int leftSize = _mid -_left + 1;
        int rightSize = _right -_mid;

        T* leftArr = new T[leftSize];
        T* rightArr = new T[rightSize];

        for(int i = 0; i < leftSize; i++) leftArr[i] = array[_left+i];

        for(int i = 0; i < rightSize; i++) rightArr[i] = array[_mid+1+i];

        int i = 0, j = 0, k = _left;

        while(i < leftSize && j < rightSize) {
            if(leftArr[i] < rightArr[j] )
                array[k++] = leftArr[i++];
            else 
                array[k++] = rightArr[j++];
        }

        while(i < leftSize) array[k++] = leftArr[i++];
        while(j < rightSize) array[k++] = rightArr[j++];

        delete [] leftArr;
        delete [] rightArr;
    }



public:
    //Constructor
    custArray(int _size) : size(_size), tailPtr(0), temp(nullptr){
        array = new T[_size];
    }

    ~custArray(){
        delete[] array;
        delete[] temp;
    }

    custArray(const custArray& other) :size(other.size), tailPtr(other.tailPtr), temp(nullptr) {
        array = new T[size];
        for(int i = 0; i < tailPtr; i++)
            array[i] = other.array[i];
    }

    custArray& operator=( const custArray& other) {
        if(this == &other) return *this;
        delete[] array;
        size = other.size;
        tailPtr = other.tailPtr;
        array = new T[size];
        for(int i = 0; i < tailPtr; i++)
            array[i] = other.array[i];
        return *this;
    }

    void setElement(const T& _data, int _index) { array[_index] = _data;}
    T getElement(int _index){return array[_index];}

    int getSize(){return size; }
    int getTail(){return tailPtr;}

    void setSize(int _newSize){size = _newSize;}
    void setPtr(int _newTail){tailPtr = _newTail;}

    void incrementPtr(){tailPtr++;}


    bool isNull(int _index) { return array[_index] == T{};}
    bool isEmpty() {return tailPtr == 0;}
    bool maxSize() {return tailPtr >= size-1;}
    bool minSize() { return ((size-1)/2) >= tailPtr;}

    bool equalElements(int _index1,  int _index2){
        return array[_index1] == array[_index2]; }

    bool indexEquals(int _index, const T& _data) { return array[_index] == _data;}
     
    T peek(int _index) {
        return array[_index];
    }

    void swapElements(int _index1, int _index2){
            T tmp = getElement(_index2);
            setElement(array[_index1], _index2);
            setElement(tmp, _index1);
    }

    bool containsElement(const T& _data){
        for(int i = 0; i < tailPtr; i++)
            if(indexEquals(i, _data)) return true;
        return false;
    }

    int returnIndex(const T& _data) {
        for( int i = 0; i < tailPtr; i++)
            if(indexEquals(i, _data)) return i;
        return -1;
    }

    int numberOfDuplicates(const T& _data) {
        int count = 0;
        for(int i = 0; i < tailPtr; i++)
            if(array[i] == _data) count++;
        return count;
    }

    int * indexDuplicates(const T& _data, int& _outCount) {
        _outCount = numberOfDuplicates(_data);
        int* duplicateIndex = new int[_outCount];
        int index = 0;
        for(int i = 0; i < tailPtr; i++)
            if(array[i] == _data) duplicateIndex[index++] = i;

        return duplicateIndex;
    }

    void printArray() {
        for(int i = 0; i < tailPtr; i++)
            std::cout<<array[i] <<" custArray\n";
    }

    void printArray(T* _printArray, int _size) {
        for(int i = 0; i < _size; i++)
            std::cout<< _printArray[i] << " array Param custArray\n";
    }

    void upsizeArray() {
        size *= 2;
        temp = new T[size];

        for(int i = 0; i < tailPtr; i++) temp[i] = array[i];
        delete [] array;
        array = temp;
        temp = nullptr;
    }

    void downsizeArray() {
        int newSize = size/ 2;
        if(tailPtr > newSize) return;
        size = newSize;
        temp = new T[size];

        for(int i = 0; i < tailPtr; i++) temp[i] = array[i];
        delete[] array;
        array = temp;
        temp = nullptr;
    }

    void addElement(const T& _data) {
        if(maxSize()) upsizeArray();
        array[tailPtr++] = _data;
    }

    void addElement(int _index, const T& _data) {
        if( _index >= tailPtr) {addElement(_data); return;}
        if(maxSize()) upsizeArray();
        int tempSize = tailPtr - _index;
        temp = new T[tempSize];
        for(int i = 0; i < tempSize; i++) temp[i] = array[i + _index];
        array[_index] = _data;
        for(int i  = 0; i < tempSize; i++) array[_index + 1 + i] = temp[i];
        tailPtr++;
        delete [] temp;
        temp = nullptr;
    }

    T removeElement(int _index) {
       if(_index >= tailPtr || _index < 0)
            return T();
        
        T removedValue = array[_index];
        temp = new T[tailPtr-1];
        for(int i = 0, j = 0; i < tailPtr; i++, j++) {
            if(i == _index) 
                j--;
            else 
                temp[j] = array[i] ; 
        }
        delete [] array;
        array = temp;
        temp = nullptr;
        --tailPtr;
        if(minSize()) downsizeArray();
        return removedValue;
    }

    T* removeElement(const T& _data) {
        int index = returnIndex(_data);
        if(index != -1) {
            T removed = removeElement(index);
            return new T(removed);
        }
        return nullptr;
    }

    bool ifRemoved(const T& _data) {
        T * removed = removeElement(_data);
        if( removed != nullptr){
            delete removed;
            return true;
        }
        return  false;
    }

    void removeAll(const T& _data) {
        T* result;
        while((result = removeElement(_data)) != nullptr)
            delete result;
    }

    void sort() {
        mergeSort(0, tailPtr-1);
    }

};

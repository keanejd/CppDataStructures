#pragma once
#include "doubleNode.hpp"
// list iterator for the double list, only used for the print functions.
template<typename T>
class itDL {
    private:
        doubleNode<T>* current;

    public:
        itDL(doubleNode<T>* _node) : current(_node) {}

        T& operator*()  { return this->current->getData(); }
        T* operator->() { return &(this->current->getData()); }

        // pre-increment
        itDL& operator++() {
            this->current = this->current->getNext();
            return *this;
        }

        // post-increment
        itDL operator++(int) {
            itDL temp = *this;
            this->current = this->current->getNext();
            return temp;
        }

        // pre-decrement
        itDL& operator--() {
            this->current = this->current->getPrev();
            return *this;
        }

        // post-decrement
        itDL operator--(int) {
            itDL temp = *this;
            this->current = this->current->getPrev();
            return temp;
        }

        bool operator==(const itDL& _other) const {
            return this->current == _other.current;
        }

        bool operator!=(const itDL& _other) const {
            return this->current != _other.current;
        }
};
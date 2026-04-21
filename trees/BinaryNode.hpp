#pragma once 

template<typename T>

class BinaryNode {
  public:
    virtual ~BinaryNode() = default;
    virtual const T & getData() const = 0;
    virtual BinaryNode * getLeft() const = 0;
    virtual BinaryNode * getRight() const = 0;
};

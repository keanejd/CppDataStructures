# C++ Data Structures

C++  implementations and testing various data structures

## Contents

- **custArray<T>** – A generic resizable array built from scratch (no ArrayList)
- **doubleList<T>** - A generic doubly linked list 
- **queue<T>** - A generic Queue,  based on the doubly linked list
- **stack<T>** - A generic Stack, based on the doubly linked list
- **animal** –   An animal object for sorting and searching

## Project Structure
```
JavaDataStructures/
|-- animal/
|-- custArray/
|-- linear/
|-- Makefile
```

## Build
```bash
make
```

## Run
```bash
make run-custarray
make run-linear
```cd 
```

## Requirements

- GCC 7+ (C++ 17)
- GNU Make
## Sample Output
```
make run
```
Outputs to `CustArray_results.txt`. `Linear_results.txt`. 
Features tested:
- Generic vector, doubly linked list, stack,  and queue
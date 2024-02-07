# Data Structures & Algorithms

![](./resources/general_tree.svg)

This repository contains a set of _data structures_ and _abstract data
type_ implementations. I have written a short disambiguation of these
and other terms, which you can read
[here](https://docs.afneville.com/cs/dsa/introduction.html).

## Branches

There is often more than a single way to create a data structure and I
have struggled to combine all of the imaginable features into a single
implementation. These branches point to a handful of the different
approaches that I have previously explored:

- [Heterogeneous List](https://github.com/afneville/DSA/tree/heterogeneous_list)
- [Associative Array](https://github.com/afneville/DSA/tree/associative_array)
- [Fundamental Implementations](https://github.com/afneville/DSA/tree/fundamental_data_structures)

## Emulating the STL

My most recent attempt is made with C++, which (like C) supports direct,
unfettered access to virtual memory, while providing useful abstraction
mechanisms. I have drawn inspiration from the API of standard template
library containers, including the role of iterators.

### Implemented Types

Most of the sequence containers of the STL can be implemented with an
array list or a linked list. A double-ended queue requires a
doubly-linked list for quick operation at its ends, but both queues and
stacks can be efficiently implemented with a forward singly-linked list
with an additional pointer to the rear.

- [x] Vector
- [x] Array List
- [x] Forward List
- [x] List
- [x] Deque
- [ ] Queue
- [ ] Priority Queue
- [ ] Stack

I also plan to implement some data structures akin to the STL's
associative containers. I have previously created less general
implementations for many of these - marked with branches.

- [ ] Tree
  - [ ] Binary Tree
  - [ ] Binary Search Tree
  - [ ] Self balancing tree
  - [ ] Binary Heap
- [ ] Map
- [ ] Set

## Build & Test

As each of the types is written as a class template, the complete
template must be available to the compiler at the point an instance is
required; the templates cannot be compiled ahead of time. Resultantly,
for each type, the whole template, including complete member function
definition, is present in a `.hpp` file in the `templates/` directory. I
have created full, type-parameterised unit tests for all user defined
types. Each test suite resides in its own source file in the `tests/`
directory.

```text
.
|-- CMakeLists.txt
|-- README.md
|-- templates
|   |-- deque.hpp
|   |-- ...
|   `-- vector.hpp
`-- tests
    |-- list_test.cpp
    |-- ...
    `-- vector_test.cpp
```

I have used [CMake](https://docs.afneville.com/dev/unix/cmake.html) to
build the project. An executable in the `build/` directory is generated
for each test suite. The test suites can be run independently and
verbosely, or a summary of the tests outcomes can be produce via
`ctest`.

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build
```
